from django.shortcuts import render

# Create your views here.
def home(request):
    return render(request, 'home.html')


def hospital(request):
    return render(request, 'hospital_page.html')


def user_login(request):
    return render(request, 'user_login.html')

def register_user(request):
    return render(request, 'user_reg.html')

def hospital_login(request):
    return render(request, 'hospital_login.html')

def register_hospital(request):
    return render(request, 'hospital_reg.html')