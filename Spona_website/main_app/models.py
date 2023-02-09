from django.db import models
from django.contrib.auth.models import User

class Device(models.Model):
    device_user = models.OneToOneField(User, on_delete=models.CASCADE)
    device_number = models.CharField(max_length=30)
    contacts = models.CharField(max_length=15)

    def __str__(self):
        return self.device_user.username + "'s device"