from django.db import models

# Create your models here.
class Vehicle(models.Model):
    user = models.OneToOneField()
    vehicle_number = models.CharField(max_length=15)
    phone1 = models.CharField(max_length=20)
    phone2 = models.CharField(max_length=20)
    phone3 = models.CharField(max_length=20)
    
class Accident(models.Model):
    vehicle = models.OneToOneField()
    latitude = models.FloatField()
    longitude = models.FloatField()
    status = models.BooleanField()
    