# ./login/views.py

from django.shortcuts import HttpResponse
from django.shortcuts import reverse

# 实现视图函数
def log_in(request):
    return HttpResponse("登录")

def log_out(request):
    return HttpResponse("注销")
