# ./forum/urls.py

from django.urls import path
from .views import write_comment, read_comment

# 导入视图函数
urlpatterns = [
    path('w_com/', write_comment, name='w_com'),
    path('r_com/', read_comment, name='r_com'),
]
