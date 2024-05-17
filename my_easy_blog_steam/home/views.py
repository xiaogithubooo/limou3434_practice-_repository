# ./home/views.py

from django.shortcuts import HttpResponse
from django.shortcuts import reverse

# 实现视图函数
def personal_details(request):
    return HttpResponse("个人信息")

def post_blog(request):
    return HttpResponse("发布博文")

def delete_blog(request):
    return HttpResponse("删除博文")