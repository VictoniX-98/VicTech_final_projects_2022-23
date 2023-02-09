from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from django.shortcuts import render, redirect
from django.contrib.auth.models import User
from django.contrib import messages
from .models import Device

# Registrations functionality
def registration(request):
    if request.user.is_authenticated:
        return redirect('home')
    else:
        if request.method == 'POST':
            name = request.POST.get('username')
            d_number = request.POST.get('device_number')
            contacts = request.POST.get('contacts')
            pass1 = request.POST.get('password')
            pass2 = request.POST.get('confirm')

            if pass1 == pass2:
                if User.objects.filter(username=name).exists():
                    messages.info(request, 'Username alread exist')
                    return redirect('register')
                if Device.objects.filter(device_number=d_number).exists():
                    messages.info(request, 'Device number alread exist')
                    return redirect('register')
                else:
                    user = User.objects.create_user(username=name, password=pass1)
                    device = Device.objects.create(device_user=user, device_number=d_number, contacts=contacts)
                    user.save()
                    device.save()
                    messages.success(request, 'Device successful registerd for ' + name)
                    return redirect('login')
            else:
                messages.error(request, 'Error: Password missmatch')
                return redirect('register')
        else:
            return render(request, 'register.html')

# Login functionality
def login_page(request):
    if request.user.is_authenticated:
        return redirect('home')
    else:
        if request.method == 'POST':
            username = request.POST.get('username')
            password = request.POST.get('password')

            user = authenticate(request, username=username, password=password)

            if user is not None:
                login(request, user)
                return redirect('home')
            else:
                messages.error(request, 'Invalid credentials')
                return redirect('login')
        else:
            return render(request, 'login.html')

# Logout method
def logout_user(request):
    logout(request)
    return redirect('login')

# Home page functionality
@login_required(login_url='login')
def home_page(request):
    return render(request, 'home.html')

@login_required(login_url='login')
def location_manager(request, user):
    context = user
    return render(request, 'map.html', {'username': context})