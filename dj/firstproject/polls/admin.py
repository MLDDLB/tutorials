import typing as tp

from email import message
from django.contrib import admin, messages
from django.core import serializers
from django.http import HttpResponse, HttpRequest
from django.utils.translation import ngettext
from django.db.models import Model

from .models import Question, Choice


# Register your models here.
class ChoiceInline(admin.TabularInline):
    model = Choice
    stack = 3

    def get_readonly_fields(
        self, 
        request: HttpRequest, 
        obj: tp.Optional[Model] = None
    ) -> tp.Union[tp.List[str], tp.Tuple[tp.Any, ...]]:
        if obj.is_published:
            return ["choice_text", "vote"]
        return []


class QuestionAdmin(admin.ModelAdmin):
    fieldsets = [
        (None, {"fields": ["question_text"]}),
        ("Date information", {"fields": ["pub_date"]}),
    ]
    inlines = [ChoiceInline]
    list_display = ("question_text", "pub_date", "was_published_recently")
    list_filter = ["pub_date"]
    search_fields = ["question_text"]
    actions = ["make_published", "make_editable", "serialize_polls"]

    def get_readonly_fields(
        self, 
        request: HttpRequest, 
        obj: tp.Optional[Model] = None,
    ) -> tp.Union[tp.List[str], tp.Tuple[tp.Any, ...]]:
        if obj.is_published:
            return ["question_text", "pub_date"]
        return []

    @admin.action(description="Serialize to json")
    def serialize_polls(self, request, queryset):
        response = HttpResponse(content_type="application/json")
        serializers.serialize(format="json", queryset=queryset, stream=response)
        return response


admin.site.register(Question, QuestionAdmin)