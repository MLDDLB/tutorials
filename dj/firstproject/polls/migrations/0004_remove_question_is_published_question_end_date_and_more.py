# Generated by Django 4.1.2 on 2022-10-21 11:35

import datetime
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('polls', '0003_question_votes_alter_question_pub_date'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='question',
            name='is_published',
        ),
        migrations.AddField(
            model_name='question',
            name='end_date',
            field=models.DateTimeField(null=True),
        ),
        migrations.AlterField(
            model_name='question',
            name='pub_date',
            field=models.DateTimeField(default=datetime.datetime(2022, 10, 21, 11, 35, 36, 877788, tzinfo=datetime.timezone.utc), verbose_name='date published'),
        ),
    ]