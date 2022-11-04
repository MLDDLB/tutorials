import datetime as dt

from django.http import HttpResponse, HttpResponseRedirect, HttpRequest
from django.shortcuts import render, get_object_or_404
from django.urls import reverse
from django.views import generic
from django.utils import timezone

from .models import Choice, Question
from .lib.validators import ValidationStatus, validate_question, validate_choices

FORMAT = "%Y-%m-%dT%H:%M"


class DetailView(generic.DetailView):
    model = Question
    template_name = "polls/details.html"

    def get_queryset(self):
        """
        Exclude any questions that aren't published yet.
        """
        return Question.objects.filter(pub_date__lte=timezone.now())


class ResultsView(generic.DetailView):
    model = Question
    template_name = "polls/results.html"

    def get_queryset(self):
        """
        Exclude any questions that aren't published yet.
        """
        return Question.objects.filter(pub_date__lte=timezone.now())


# Create your views here.
def index(request):
    latest_questions_list = Question.objects.filter(pub_date__lte=timezone.now()).order_by("-pub_date")[:5]
    context = {
        "latest_questions_list": latest_questions_list,
    }
    return render(request, "polls/index.html", context)


def new(request: HttpRequest) -> HttpResponse:
    if request.method == "GET":
        context = request.GET.dict()
        return render(request, "polls/new.html", context)

    if request.method == "POST":
        question_text, pub_date, end_date = request.POST["question_text"], \
                                            dt.datetime.strptime(request.POST["pub_date"], FORMAT), \
                                            dt.datetime.strptime(request.POST["end_date"], FORMAT)

        validation_results = validate_question(question_text=question_text,
                                            pub_date=pub_date, 
                                            end_date=end_date,)

        if validation_results.status == ValidationStatus.OK:
            new_question = Question(question_text=question_text, pub_date=pub_date, end_date=end_date)
            new_question.save()
        elif validation_results.status == ValidationStatus.ERROR:
            context = {
                "question_text": question_text,
                "pub_date": pub_date,
                "end_date": end_date,
                "choice_list": request.POST.getlist("choice_list")
            }
            return HttpResponseRedirect(reverse("polls:new"))

        choice_list = request.POST.getlist("choice_list")
        validation_results = validate_choices(choice_list=choice_list)

        for choice in choice_list:
            new_question.choice_set.create(choice_text=choice)

        # add confirmation view
        return HttpResponseRedirect(reverse("polls:index"))


def add_choice(request: HttpRequest) -> HttpResponse:
    context = request.GET.dict()
    if "choice_list" not in context:
        context["choice_list"] = [""]
    else:
        context["choice_list"] = request.GET.getlist("choice_list")
        context["choice_list"].append("")
    return render(request, "polls/new.html", context)


def vote(request, question_id):
    question = get_object_or_404(Question, pub_date__lte=timezone.now(), pk=question_id)
    try:
        selected_choice = question.choice_set.get(pk=request.POST['choice'])
    except (KeyError, Choice.DoesNotExist):
        error_message = "You didn't select a valid choice"
        return render(
            request,
            "polls/details.html",
            {
                "question": question,
                "error_message": error_message,
            })
    question.votes += 1
    selected_choice.vote += 1
    question.save()
    selected_choice.save()
    return HttpResponseRedirect(reverse("polls:results", args=(question_id,)))