# ./login/urls.py

from django.contrib import admin

from django.urls import path
from .views import log_in, log_out

# 导入视图函数
urlpatterns = [
    path('admin/', admin.site.urls),
    path('login/', log_in, name='login'),
    path('logout/', log_out, name='logout'),
]
