from django.urls import path
from . import views

urlpatterns = [
    path('', views.home, name='home'),
    path('hospital/', views.hospital, name='hospital'),
    path('hospital_login/', views.hospital_login, name='hospital_login'),
    path('hospital_reg/', views.register_hospital, name='hospital_reg'),
    path('user_login/', views.user_login, name='user_login'),
    path('user_reg/', views.register_user, name='user_reg')
]