# ./main_app/urls.py

from django.contrib import admin
from django.urls import path
from django.urls import include

home_name = 'home'

urlpatterns = [
    path('admin/', admin.site.urls),
    path('index/', include("index.urls")),
    path('home/', include("home.urls")),
    path('forum/', include("forum.urls")),
]