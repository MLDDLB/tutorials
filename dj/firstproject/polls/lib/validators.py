from logging.config import valid_ident
import typing as tp
import datetime as dt

from enum import IntEnum

from django.utils import timezone

FORMAT = "%Y-%m-%dT%H:%M"


class ValidationStatus(IntEnum):
    OK = 1
    WARNING = 2
    ERROR = 3


class Validator(object):
    
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

    @property
    def messages(self):
        return self._messages

    def update_status(self, status: ValidationStatus, message: str):
        if not isinstance(status, ValidationStatus):
            raise ValueError()

        if not isinstance(message, str):
            raise ValueError()

        if self._status < status:
            self._status = status

        self._messages.append(message)


class DataValidator(Validator):

    def validate_question(
        self,
        question_text: str,
        pub_date: dt.datetime,
        end_date: dt.datetime,
        ) -> None:
        TIME_ERROR = dt.timedelta(minutes=10)

        if not question_text:
            self.update_status(ValidationStatus.ERROR, "Question text field can't be empty.")
        
        if not pub_date:
            self.update_status(ValidationStatus.ERROR, "Publication date field can't be empty.")
        else:
            pub_date = dt.datetime.strptime(pub_date, FORMAT)
            if pub_date < timezone.make_naive(timezone.now()) - TIME_ERROR:
                self.update_status(ValidationStatus.ERROR, "Publication date can't be set in the past")

            if end_date:
                end_date = dt.datetime.strptime(end_date, FORMAT)
                if end_date < pub_date:
                    self.update_status(ValidationStatus.ERROR, "End date can't be set earlier than the publication date")
            elif not end_date:
                self.update_status(ValidationStatus.WARNING, "End date is not set, the poll will be archived after 3 days without votes.")
        
        return


    def validate_choices(self, choice_list: tp.List[str]) -> None:
        if not choice_list:
            self.update_status(ValidationStatus.ERROR, "You have to add atleast one choice.")
        else :
            if len(choice_list) == 1:
                self.update_status(ValidationStatus.WARNING, "You added only one choice, do you want to continue?")

            for i in range(len(choice_list)):
                if not choice_list[i]:
                    self.update_status(ValidationStatus.ERROR, "Choice number {} is empty".format(i))

        return 

# TODO: Add request validation functionality to validate headers
class RequestValidator(Validator):
    pass
