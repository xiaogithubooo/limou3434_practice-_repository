""" 文件描述
存放使用 flask 过程中使用的插件
"""


from flask_sqlalchemy import SQLAlchemy
from flask_mail import Mail
from flask_migrate import Migrate


db = SQLAlchemy()   # 数据库操作对象
migrate = Migrate() # 模型同步操作对象
mail = Mail()       # 邮箱操作对象
