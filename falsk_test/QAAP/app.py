from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
import config

# 创建 Flask 对象
app = Flask(__name__)
app.config.from_object(config) # 引入配置文件内的内容，之前的数据库就不能直接在本文件中导入了，需要写到对应的配置文件中

db = SQLAlchemy(app)

# 创建 Migrate 对象
migrate = Migrate(app, db)

# 创建模板
class User(db.Model):
    __tablename__ = "user"
    id = db.Column(db.Integer, primary_key=True, autoincrement=True) # id
    username = db.Column(db.String(100), nullable=False) # 用户名字段
    password = db.Column(db.String(100), nullable=False) # 用户密码字段
    email = db.Column(db.String(100)) # 新增的字段，再做命令行操作
    signature = db.Column(db.String(100)) # 再次新增的字段，再做命令行操作
    age = db.Column(db.Integer) # 再再次新增的字段，再做命令行操作

# 路由和视图函数的定义
# ...
    
# 启动 Web 后端服务
if __name__ == '__main__':
    app.run(debug=True)