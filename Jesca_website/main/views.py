from django.shortcuts import render

# Create your views here.
def admin(request):
    return render(request, 'admin.html')

def home(request):
    return render(request, 'customer.html')

def login(request):
    return render(request, 'login.html')

def register(request):
    return render(request, 'register.html')