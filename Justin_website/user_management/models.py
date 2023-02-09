from django.db import models

class Driver(models.Model):
    username = models.CharField(max_length=200)
    vehicle_number = models.CharField(max_length=10)
    email = models.EmailField()
    contact = models.CharField(max_length=15)

    def __str__(self):
        return self.username + ' : ' + self.vehicle_number


class Casses(models.Model):
    driver = models.ForeignKey(Driver, null=True, on_delete=models.CASCADE)
    date = models.DateField()
    time = models.TimeField()
    latitude = models.FloatField()
    longtude = models.FloatField()
    payment = models.BooleanField()

    def __str__(self):
        return str(self.driver)
