from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('test/', views.test, name='hospital'),
    path('login/', views.login, name='login'),
    path('registration/', views.register, name='registration')
]