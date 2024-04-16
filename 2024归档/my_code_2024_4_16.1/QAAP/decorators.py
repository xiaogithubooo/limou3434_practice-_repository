""" 文件描述
一些减少复用的装饰器
"""


from functools import wraps
from flask import g, redirect

# 检查是否已经登录
def login_required(func):
    # 相当于 login_required(func)(args)
    # 保留 func 的信息
    @wraps(func)
    def inner(*args, **kwargs):
        if g.user: # 判断有无进行登录
            return func(*args, **kwargs) 
        else:
            return redirect('/auth/login')
    return inner