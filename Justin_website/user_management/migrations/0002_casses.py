# Generated by Django 4.1.5 on 2023-02-02 00:56

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('user_management', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='Casses',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('date', models.DateField()),
                ('time', models.TimeField()),
                ('latitude', models.FloatField()),
                ('longtude', models.FloatField()),
                ('payment', models.BooleanField()),
                ('driver', models.ForeignKey(null=True, on_delete=django.db.models.deletion.CASCADE, to='user_management.driver')),
            ],
        ),
    ]
