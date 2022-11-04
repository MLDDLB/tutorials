from logging.config import valid_ident
import typing as tp
import datetime as dt

from enum import IntEnum

from django.utils import timezone


class ValidationStatus(IntEnum):
    OK = 1
    WARNING = 2
    ERROR = 3


class ValidationResult(object):
    
    def __init__(
        self,
        status: ValidationStatus = ValidationStatus.OK,
    ) -> None:
        if not isinstance(status, ValidationStatus):
            raise ValueError("Status attribute can only be an instance of ValidationStatus enum")

        self._status = status
        self._messages = []

    def __str__(self):
        return "{}: {}".format(self._status.name, self._messages)

    @property
    def status(self):
        return self._status

    def update_status(self, status: ValidationStatus, message: str):
        if not isinstance(status, ValidationStatus):
            raise ValueError()

        if not isinstance(message, str):
            raise ValueError()

        if self._status < status:
            self._status = status

        self._messages.append(message)
        


def validate_question(question_text: str, pub_date: dt.datetime, end_date: dt.datetime) -> ValidationResult:
    TIME_ERROR = dt.timedelta(minutes=10)

    validation_results = ValidationResult()

    if not question_text:
        validation_results.update_status(ValidationStatus.ERROR, "Question text field can't be empty.")
    
    if not pub_date:
        validation_results.update_status(ValidationStatus.ERROR, "Publication date field can't be empty.")
    else:
        if pub_date < timezone.make_naive(timezone.now()) - TIME_ERROR:
            validation_results.update_status(ValidationStatus.ERROR, "Publication date can't be set in the past")

        if end_date and end_date < pub_date:
            validation_results.update_status(ValidationStatus.ERROR, "End date can't be set earlier than the publication date")
        elif not end_date:
            validation_results.update_status(ValidationStatus.WARNING, "End date is not set, the poll will be archived after 3 days without votes.")

    return validation_results


def validate_choices(choice_list: tp.List[str]) -> ValidationResult:
    validation_results = ValidationResult()

    if not choice_list:
        validation_results.update_status(ValidationStatus.ERROR, "You have to add atleast one choice.")
    elif len(choice_list):
        validation_results.update_status(ValidationStatus.WARNING, "You added only one choice, do you want to continue?")
    else:
        for i in range(len(choice_list)):
            if not choice_list[i]:
                validation_results.update_status(ValidationStatus.ERROR, "Choice number {} is empty".format(i))
