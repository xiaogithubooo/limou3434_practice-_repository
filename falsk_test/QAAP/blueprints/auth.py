""" 文件描述
用户授权逻辑相关蓝图
"""

from flask import Blueprint, render_template, request, jsonify, redirect, url_for
from exts import mail, db
from flask_mail import Message 
import string
import random
from models import EmailCaptchaModel
from models import UserModel
from .forms import RegisterForm
from werkzeug.security import generate_password_hash

# 创建蓝图对象
bp = Blueprint('auth', __name__, url_prefix='/auth')

# 获取注册界面和提供用户注册的接口
@bp.route('/register', methods=['GET', 'POST']) # 设置两者请求方式
def register():
    # 1.客户端从服务器获取数据
    if request.method == 'GET':
        return render_template('register.html')
    else: # 2.客户端给服务端提交数据(request.method == 'POST')
        form = RegisterForm(request.form) # 将数据扔给该类来创建对象, form 就是前端提交表单时的那一个标签, 这里就可以拿到表单数据
        if form.validate(): # (1)通过表单, 则在数据表中插入新记录
            username = form.username.data   # 获取经过验证的表单数据(用户名字)
            password = form.password.data   # 获取经过验证的表单数据(用户密码)
            email = form.email.data         # 获取经过验证的表单数据(用户邮箱)
            
            a_user = UserModel(username=username, password=generate_password_hash(password), email=email) # 注意密码需要被加密再存储
            db.session.add(a_user)
            db.session.commit()

            # 若需要表单提交成功后跳转到另一个页面, 应使用 redirect()
            # 若需要渲染模板, 应使用 render_template()
            return redirect('/auth/login') # 重定向
        else: # (2)拦截表单, 重定向到注册页面
            print(form.errors)
            return redirect(url_for('auth.register')) # 使用 url_for() 可以把视图函数转化为 URL, 和上面时同一种写法

# 生成和发送邮箱验证码接口
@bp.route('/email_captcha')
def email_captcha():
    # (1)生成随机验证码
    source = string.digits * 5
    captcha = random.sample(source, 5)
    captcha = ''.join(captcha)

    # (2)发送验证码
    # 使用 /email_captcha/<email>
    # 使用 /email_captcha?email=...
    email = request.args.get('email')
    message = Message(
        subject="问答平台验证码",
        recipients=[email],
        body=f"您的个人验证码为 {captcha} 请不要泄露给他人。"
    )
    mail.send(message) 
    # TODO: 由于这里需要先发给腾讯服务器, 因此会陷入 IO 阻塞, 可以考虑做异步

    # (3)存储验证码以便后续检验（MySQL/memcached/redis）
    existing_email_captcha = EmailCaptchaModel.query.filter_by(email=email).first()

    if existing_email_captcha: # 如果已经存在记录，则更新 captcha 值，否则创建新记录
        existing_email_captcha.captcha = captcha
        db.session.merge(existing_email_captcha)
    else:
        new_email_captcha = EmailCaptchaModel(email=email, captcha=captcha)
        db.session.add(new_email_captcha)

    db.session.commit()
    return jsonify({'code': 200, 'message': 'get captcha succeed', 'data': None}) # 由于是 HTML+JavaScript(Ajax) 编程, 因此最好符合 RESTful API

# 获取登录界面接口
@bp.route('/login')
def login():
    return render_template('login.html')
