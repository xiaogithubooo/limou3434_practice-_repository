from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
import os

# 通过当前文件名创建 Flask 对象
app = Flask(__name__)

# 配置 app.config 内连接数据库的信息
app.config['SQLALCHEMY_DATABASE_URI'] = (
    f"mysql+pymysql://"
    f"{os.getenv('EIMOU_DATABASE_USER')}:{os.getenv('EIMOU_DATABASE_PASSWORD')}@"
    f"{os.getenv('EIMOU_DATABASE_HOST')}:3306/{os.getenv('EIMOU_DATABASE_NAME')}"
    "?charset=utf8mb4"
)

# 通过 Flask 对象创建 SQLAlchemy 对象
db = SQLAlchemy(app)

# 创建迁移对象
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

# # 同步创建（不要用这个方式）
# with app.app_context():
#     # (1)检查模型：create_all() 会检查 SQLAlchemy ORM 模型以确定哪些表需要被创建
#     # (2)创建缺失表：对于每个需要创建的表，create_all() 会在数据库中生成相应的 SQL 语句来创建该表
#     db.create_all() # 同步数据库
    
# 路由和视图函数的定义
# ...
    
# 启动 Web 后端服务
if __name__ == '__main__':
    app.run(debug=True)