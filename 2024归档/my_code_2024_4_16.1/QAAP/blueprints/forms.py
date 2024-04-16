""" 文件描述
检验前端的表单提交的格式
"""

import wtforms
from wtforms.validators import Email, Length, EqualTo, InputRequired
from models import UserModel
from models import EmailCaptchaModel
from exts import db

# 定义注册验证器子类
class RegisterForm(wtforms.Form): # 这里的 wtforms.Form 实际上就是检验表单提交的数据
    # (1)表单数据格式的检查(添加给每个表单元素一个检查器)
    email = wtforms.StringField(validators=[Email(message="邮箱格式错误")]) # 为 email 字段添加了一个验证器 Email, 检验邮箱格式
    captcha = wtforms.StringField(validators=[Length(min=5, max=5, message="验证码格式错误, 应有 5 位数字")]) # ..., 检验验证码格式
    username = wtforms.StringField(validators=[Length(min=3, max=20, message="用户名格式错误, 不少于 3 位, 不大于 20 位")]) # ..., 检验用户名格式
    password = wtforms.StringField(validators=[Length(min=6, max=20, message="密码格式错误, 不少于 6 位, 不大于 20 位")]) # ..., 检验密码格式
    password_confirm = wtforms.StringField(validators=[EqualTo("password")]) # ..., 检验是否成功确认密码

    # 以下 WTForms 中自定义的验证方法会在调用表单的 validate() 时自动触发
    
    # (2)自定义的检查函数(WTForms 会根据自定义验证函数的命名约定 validate_<field_name> 来区分检验不同字段时调用哪个函数)
    # a.检查邮箱是否被注册
    def validate_email(self, field):
        a_email = field.data
        result = UserModel.query.filter_by(email=a_email).first() # 在数据表中查找是否存在该用户
        if result:
            raise wtforms.ValidationError(message="邮箱已被注册")

    # b.检查验证码是否正确, 正确时会把验证码删除
    def validate_captcha(self, field):
        a_captcha = field.data
        a_email = self.email.data
        result = EmailCaptchaModel.query.filter_by(email=a_email, captcha=a_captcha).first() # 在数据表中查找用户和验证码是否一一对应
        if not result:
            raise wtforms.ValidationError(message="验证码错误, 请重新获取")
        else: # 如果验证完成就可以删除该记录, 
            db.session.delete(result)
            db.session.commit()
            # TODO: 如果这里的每次删除影响效率, 就需要另写异步的脚本, 让数据库定时删除无用的验证码, 并且最好在数据库中设计一个标志位, 标志验证码是否无效

# 定义登录验证器子类
class LoginForm(wtforms.Form): # 这里的 wtforms.Form 实际上就是检验表单提交的数据
    # 表单数据格式的检查(添加给每个表单元素一个检查器)
    email = wtforms.StringField(validators=[Email(message="邮箱格式错误")]) # 为 email 字段添加了一个验证器 Email, 检验邮箱格式
    password = wtforms.StringField(validators=[Length(min=6, max=20, message="密码格式错误, 不少于 6 位, 不大于 20 位")]) # ..., 检验密码格式
    # TODO: 这里也有一个小 bug, 用户登录最好也做一个验证码检验, 否者也有可能遭受攻击
    # TODO: 前面关于数据库账户密码的凭证检验可以尝试迁移到这里, 干脆一起检查了

class QuestionForm(wtforms.Form): # 这里的 wtforms.Form 实际上就是检验表单提交的数据
    title = wtforms.StringField(validators=[Length(min=2, max=30, message="标题字数为 2 到 30 个字")]) # 标题检查
    content = wtforms.StringField(validators=[Length(min=10, max=1000, message="内容字数为 10 到 1000 个字")]) # 内容检查

class AnswerForm(wtforms.Form): # 这里的 wtforms.Form 实际上就是检验表单提交的数据
    content = wtforms.StringField(validators=[Length(min=3, max=1000, message="内容字数为 3 到 1000 个字")]) # 内容检查
    question_id = wtforms.StringField(validators=[InputRequired(message='必须传入问题 id')]) # 检查帖子 id