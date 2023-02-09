from django.urls import path
from . import views

urlpatterns = [
    path('', views.home_page, name='home'),
    path('login/', views.login_page, name='login'),
    path('logout/', views.logout_user, name='logout'),
    path('registration/', views.registration, name='register'),
    path('map/<str:user>', views.location_manager, name='location'),
]