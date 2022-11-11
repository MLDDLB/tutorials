import datetime

from django.test import TestCase
from django.urls import reverse
from django.utils import timezone

from .models import Question


def create_question(question_text: str, days: int) -> None:
    """
    Create a question with the given `question_text` and published the
    given number of `days` offset to now (negative for questions published
    in the past, positive for questions that have yet to be published).
    """
    pub_date = timezone.now() + datetime.timedelta(days=days)
    return Question.objects.create(question_text=question_text, pub_date=pub_date)

# Create your tests here.
class QuestionModelTests(TestCase):

    def test_was_published_recently(self):
        '''
        was_published_recently() returns "True" for questions whose pub_date is not older than 1 day
        '''
        question = Question(question_text='test', pub_date=timezone.now()-datetime.timedelta(hours=8))
        self.assertIs(question.was_published_recently(), True)

    def test_was_published_not_recently(self):
        '''
        was_published_recently() returns "False" for questions whose pub_date is older than 1 day
        '''
        question = Question(question_text='test', pub_date=timezone.now()-datetime.timedelta(days=2))
        self.assertIs(question.was_published_recently(), False)

    def test_was_published_recently_in_the_future(self):
        '''
        was_published_recently() returns "False" for questions whose pub_date is in the future
        '''
        question = Question(question_text='test', pub_date=timezone.now()+datetime.timedelta(days=30))
        self.assertIs(question.was_published_recently(), False)


class QuestionIndexViewTests(TestCase):
    
    def test_no_question(self):
        """
        If no questions exist, appropraite message is displayed.
        """
        response = self.client.get(reverse("polls:index"))

        self.assertEqual(response.status_code, 200)
        self.assertContains(response, "No questions available")
        self.assertQuerysetEqual(response.context["latest_questions_list"], [])

    def test_past_question(self):
        """
        Questions with pub_date in the past are displayed on the index page.
        """
        question = create_question("A question published in the past", -1)

        response = self.client.get(reverse("polls:index"))

        self.assertEqual(response.status_code, 200)
        self.assertQuerysetEqual(response.context["latest_questions_list"], [question])

    def test_future_question(self):
        """
        Questions with pub_date in the future aren't displayed on the index page.
        """
        question = create_question("A question to be published in the future", 1)

        response = self.client.get(reverse("polls:index"))

        self.assertEqual(response.status_code, 200)
        self.assertContains(response, "No questions available")
        self.assertQuerysetEqual(response.context["latest_questions_list"], [])

    def test_future_and_past_question(self):
        """
        If there are questions with pub_date's in the past and in the future,
        only those whose pub_date is in the past are displayed.
        """
        past_question = create_question("A question published in the past", -1)
        future_question = create_question("A question to be published in the future", 1)

        response = self.client.get(reverse("polls:index"))

        self.assertEqual(response.status_code, 200)
        self.assertQuerysetEqual(response.context["latest_questions_list"], [past_question])

    def test_two_past_questions(self):
        """
        Up to five last questions with pub_date in the past are displayed.
        """
        first_question = create_question("First question", -1)
        second_question = create_question("Second question", -2)

        response = self.client.get(reverse("polls:index"))

        self.assertEqual(response.status_code, 200)
        self.assertQuerysetEqual(response.context["latest_questions_list"], [first_question, second_question])

    def test_six_past_questions(self):
        """
        Only the last five questions with pub_date in the past are displayed.
        """
        questions_list = [create_question("{} question".format(i), -i) for i in range(6)]

        response = self.client.get(reverse("polls:index"))

        self.assertEqual(response.status_code, 200)
        self.assertQuerysetEqual(response.context["latest_questions_list"], questions_list[:5])


class QuestionDetailsViewTest(TestCase):

    def test_past_question(self):
        """
        Corretctly display details of the published question.
        """
        question = create_question("A question published in the past", -1)

        response = self.client.get(reverse("polls:details", args=(question.id,)))

        self.assertEqual(response.status_code, 200)
        self.assertEqual(response.context["question"], question)

    def test_future_question(self):
        """
        return an error if the question is set to be published in the future.
        """
        question = create_question("A question to be published in the future", 1)

        response = self.client.get(reverse("polls:details", args=(question.id,)))

        self.assertEqual(response.status_code, 404)

    def test_nonexistent_question(self):
        """
        return an error if the question doesn't exist.
        """
        question = create_question("A question to be published in the future", -1)

        response = self.client.get(reverse("polls:details", args=(question.id+1,)))

        self.assertEqual(response.status_code, 404)