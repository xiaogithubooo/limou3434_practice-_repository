""" 文件描述
设计数据库的数据表对应的 ORM 模型
远端的数据库创建语法为: create database qaap character set utf8mb4 collate utf8mb4_unicode_ci;
"""

from exts import db
from datetime import datetime

# 用户数据表
class UserModel(db.Model):
    __tablename__ = 'user'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True, nullable=False)
    username = db.Column(db.String(100), nullable=False)
    password = db.Column(db.String(200), nullable=False)
    email = db.Column(db.String(100), nullable=False, unique=True)
    join_time = db.Column(db.DateTime, default=datetime.now) # 注意这里的 now 是一个方法，这里只是传递一个方法，可以把当前用户添加进数据库的时间记录下来

# 验证码数据表   
class EmailCaptchaModel(db.Model):
    __tablename__ = 'email_captcha'
    email = db.Column(db.String(100), primary_key=True, nullable=False)
    captcha = db.Column(db.String(100), nullable=False)

# 提问内容数据表
class QuestionModel(db.Model):
    __tablename__ = 'question'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    title = db.Column(db.String(100), nullable=False)
    content = db.Column(db.Text, nullable=False)
    create_time = db.Column(db.DateTime, default=datetime.now)
    author_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False) # 外键: 对应的提问作者 id

    # 关联数据表, 反向引用名称为 questions, 若有名为 a_user
    # 的 UserModel 对象则可以通过 a_user.questions 来获取该用户发布的所有问题
    author = db.relationship(UserModel, backref='questions')

# 评论内容数据表
class AnswerModel(db.Model):
    __tablename__ = 'answer'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    content = db.Column(db.Text, nullable=False)
    create_time = db.Column(db.DateTime, default=datetime.now)
    question_id = db.Column(db.Integer, db.ForeignKey('question.id'), nullable=False) # 外键: 对应的提问 id
    author_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False) # 外键: 对应的评论用户 id
    
    question = db.relationship(QuestionModel, backref=db.backref('answers', order_by=create_time.desc())) 
    author = db.relationship(UserModel, backref='answers')
