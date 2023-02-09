from django.db import models

class Informations(models.Model):
    vehicle_number = models.CharField(max_length=10)
    date = models.DateField()
    time = models.TimeField()
    description = models.TextField()
    latitude = models.FloatField()
    longitude = models.FloatField()

    def __str__(self):
        return self.vehicle_number
