# ./home/home.py

from django.urls import path
from .views import personal_details, post_blog, delete_blog

# 导入视图函数
urlpatterns = [
    path('per_det/', personal_details, name='per_det'),
    path('p_blog/', post_blog, name='p_blog'),
    path('d_blog/', delete_blog, name='d_blog'),
]
