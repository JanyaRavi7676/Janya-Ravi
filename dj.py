from django.shortcuts import render, redirect
from .models import FoodItem, UserFoodItem
from django.contrib.auth.decorators import login_required
from django.utils import timezone

@login_required
def home(request):
    foods = FoodItem.objects.all()
    return render(request, 'home.html', {'foods': foods})

@login_required
def add_food(request):
    if request.method == 'POST':
        food_id = request.POST.get('food_id')
        quantity = int(request.POST.get('quantity', 1))
        food = FoodItem.objects.get(id=food_id)
        UserFoodItem.objects.create(
            user=request.user, fooditem=food, quantity=quantity, date=timezone.now().date()
        )
        return redirect('summary')
    foods = FoodItem.objects.all()
    return render(request, 'add_food.html', {'foods': foods})

@login_required
def summary(request):
    todays_foods = UserFoodItem.objects.filter(user=request.user, date=timezone.now().date())
    total_calories = sum([f.fooditem.calories * f.quantity for f in todays_foods])
    return render(request, 'summary.html', {'records': todays_foods, 'total': total_calories})
from django.shortcuts import render, redirect
from .models import FoodItem, UserFoodItem
from django.contrib.auth.decorators import login_required
from django.utils import timezone

@login_required
def home(request):
    foods = FoodItem.objects.all()
    return render(request, 'home.html', {'foods': foods})

@login_required
def add_food(request):
    if request.method == 'POST':
        food_id = request.POST.get('food_id')
        quantity = int(request.POST.get('quantity', 1))
        food = FoodItem.objects.get(id=food_id)
        UserFoodItem.objects.create(
            user=request.user, fooditem=food, quantity=quantity, date=timezone.now().date()
        )
        return redirect('summary')
    foods = FoodItem.objects.all()
    return render(request, 'add_food.html', {'foods': foods})

@login_required
def summary(request):
    todays_foods = UserFoodItem.objects.filter(user=request.user, date=timezone.now().date())
    total_calories = sum([f.fooditem.calories * f.quantity for f in todays_foods])
    return render(request, 'summary.html', {'records': todays_foods, 'total': total_calories})
from django.shortcuts import render, redirect
from .models import FoodItem, UserFoodItem
from django.contrib.auth.decorators import login_required
from django.utils import timezone

@login_required
def home(request):
    foods = FoodItem.objects.all()
    return render(request, 'home.html', {'foods': foods})

@login_required
def add_food(request):
    if request.method == 'POST':
        food_id = request.POST.get('food_id')
        quantity = int(request.POST.get('quantity', 1))
        food = FoodItem.objects.get(id=food_id)
        UserFoodItem.objects.create(
            user=request.user, fooditem=food, quantity=quantity, date=timezone.now().date()
        )
        return redirect('summary')
    foods = FoodItem.objects.all()
    return render(request, 'add_food.html', {'foods': foods})

@login_required
def summary(request):
    todays_foods = UserFoodItem.objects.filter(user=request.user, date=timezone.now().date())
    total_calories = sum([f.fooditem.calories * f.quantity for f in todays_foods])
    return render(request, 'summary.html', {'records': todays_foods, 'total': total_calories})
