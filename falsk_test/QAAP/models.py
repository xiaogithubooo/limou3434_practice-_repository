""" 文件描述
设计数据库的数据表对应的 ORM 模型
远端的数据库创建语法为: create database qaap character set utf8mb4 collate utf8mb4_unicode_ci;
"""

from exts import db
from datetime import datetime

class UserModel(db.Model):
    __tablename__ = 'user'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    username = db.Column(db.String(100), nullable=False)
    password = db.Column(db.String(200), nullable=False)
    email = db.Column(db.String(100), nullable=False, unique=True)
    join_time = db.Column(db.DateTime, default=datetime.now) # 注意这里的 now 是一个方法，这里只是传递一个方法，可以把当前用户添加进数据库的时间记录下来
    
class EmailCaptchaModel(db.Model):
    __tablename__ = 'email_captcha'
    email = db.Column(db.String(100), primary_key=True, nullable=False)
    captcha = db.Column(db.String(100), nullable=False)
