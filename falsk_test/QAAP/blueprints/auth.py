""" 文件描述
用户授权逻辑相关蓝图
"""

from flask import Blueprint, render_template
from exts import mail
from flask_mail import Message

bp = Blueprint(
    'auth', # 设置蓝图名
    __name__, # 设置传入当前文件名
    url_prefix='/auth' # 设置 url 前缀，之后所有的视图函数都必须以该前缀为开头
) # 之后的视图函数都使用这个 bp 对象来创建

# 注册视图函数
@bp.route('/register')
def register():
    return render_template('register.html')

# 登录视图函数
@bp.route('/login')
def login():
    return render_template('login.html')

# 邮箱测
@bp.route('/emil')
def emil():
    msg = Message(
        subject="测试",
        body = "This is the email body"
    )
    mail.send(msg)
    return "Message sent!" 