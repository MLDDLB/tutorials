from django.urls import path

from . import views

app_name = "polls"
urlpatterns = [
    path("", views.index, name="index"),
    path("archive/", views.archive, name="archive"),
    path("new/", views.new, name="new"),
    path("<int:pk>/", views.DetailView.as_view(), name="details"),
    path("<int:pk>/results/", views.ResultsView.as_view(), name="results"),
    path("<int:question_id>/vote/", views.vote, name="vote"),
    path("new/add_choice", views.add_choice, name="add_choice"),
]