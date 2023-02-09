from django.urls import path
from main import views

urlpatterns = [
    # This is admin page link url
    path('admin/', views.admin, name='admin'),
   
    # This is other page link urls
    path('', views.home, name='home'),
    path('login/', views.login, name='login'),
    path('register/', views.register, name='register')
]