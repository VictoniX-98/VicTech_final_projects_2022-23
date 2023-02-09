from django.urls import path
from user_management import views

urlpatterns = [
    path('', views.home, name='home'),
    path('login/', views.user_login, name='login'),
    path('logout/', views.user_logout, name='logout'),
    path('registration/', views.registration, name='registration'),
    path('map/<int:case_id>', views.manage_location, name='location'),
]