# ./forum/views.py

from django.shortcuts import HttpResponse
from django.shortcuts import reverse

# 实现视图函数
def write_comment(request):
    return HttpResponse("发评论")

def read_comment(request):
    return HttpResponse("读评论")