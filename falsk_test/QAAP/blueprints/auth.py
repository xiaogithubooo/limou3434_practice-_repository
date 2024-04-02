""" 文件描述
用户授权逻辑相关蓝图
"""

from flask import Blueprint, render_template, request, jsonify, redirect, url_for, session
from exts import mail, db
from flask_mail import Message 
import string
import random
from models import EmailCaptchaModel
from models import UserModel
from .forms import RegisterForm, LoginForm
from werkzeug.security import generate_password_hash, check_password_hash


# 创建蓝图对象
bp = Blueprint('auth', __name__, url_prefix='/auth')


# 生成、发送、存储邮箱验证码接口
@bp.route('/email_captcha') 
def email_captcha():
    # (1)生成随机验证码
    source = string.digits * 5
    captcha = random.sample(source, 5)
    captcha = ''.join(captcha)

    # (2)发送验证码
    # 使用 /email_captcha/<email>
    # 使用 /email_captcha?email=... 我使用第二种, 更加方便也更加自由
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

# 获取注册界面、提供用户注册的接口
@bp.route('/register', methods=['GET', 'POST'])
def register():
    # 1.客户端从服务器获取数据(GET 明文传输)
    if request.method == 'GET': # request 用来获取请求消息, 另外一个 response 是用来获取相应消息的
        return render_template('register.html')
    
    # 2.客户端给服务端提交数据(request.method == 'POST', 有表单数据)
    else:
        form = RegisterForm(request.form) # 将表单数据扔给该类来创建一个实例对象, form 就是前端提交表单时的那一个标签, 这里就可以拿到表单数据
        
        # (1)校验通过, 获取表单, 存储用户账户到数据库
        if form.validate(): # 检查表单中的每个字段是否符合预定义的验证规则, 同时调用不同的自定义校验函数
            username = form.username.data   # 获取经过验证的表单数据(用户名字)
            password = form.password.data   # 获取经过验证的表单数据(用户密码)
            email = form.email.data         # 获取经过验证的表单数据(用户邮箱)
            a_user = UserModel(username=username, password=generate_password_hash(password), email=email) # 注意密码需要被加密再存储
            db.session.add(a_user)
            db.session.commit()
            # 若需要表单提交成功后跳转到另一个页面, 应使用 redirect()
            # 若单纯需要渲染模板, 应使用 render_template()
            return redirect('/auth/login') # 重定向
        # (2)校验失败, 拦截表单, 重定向到注册页面
        else:
            print(form.errors) # TODO: 这里只是在控制台打印错误, 我认为应该返回客户端显示错误
            return redirect('/auth/register') # 重定向

# 获取登录界面、提供用户登录的接口
@bp.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'GET':
        return render_template('login.html')
    else:
        form = LoginForm(request.form)
        if form.validate():
            email = form.email.data
            password = form.password.data
            user = UserModel.query.filter_by(email=email).first()
            if not user:
                print("邮箱不存在!") # TODO: 还可以尝试在这里设置日志, 检查长期使用不存在邮箱登录的 IP 地址进行封禁
                return redirect('/auth/login')
                # TODO: 这里也做得有些简单粗暴, 直接重新返返回登录页面了, 最好是返回 JSON 数据交给客户端
            else:
                if check_password_hash(pwhash=user.password, password=password):
                    # 设置 cookic, 帮助用户进行长久登录
                    session['user_id'] = user.id # 当作数组来用即可, 会自动加密存储到客户端自己的浏览器中, 可以在开发者工具中查看
                    return redirect('/qa/index')
                else:
                    print("密码不正确!")
                    return redirect('login')
                    # TODO: 这里也做得有些简单粗暴, 直接重新返返回登录页面了, 最好是返回 JSON 数据交给客户端
        else:
            print(form.errors) # TODO: 这里只是在控制台打印错误, 我认为应该返回客户端显示错误
            return redirect('login')
        
# 退出登录接口
@bp.route('/logout')
def logout():
    session.clear() # 去除所有得 cookie
    return redirect('/')