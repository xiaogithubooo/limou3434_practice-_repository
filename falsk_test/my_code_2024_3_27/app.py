from flask import Flask
from flask_sqlalchemy import SQLAlchemy
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

# 创建模板
class User(db.Model):
    __tablename__ = "user" # 设置数据库的名字
    id = db.Column(db.Integer, primary_key=True, autoincrement=True) # id 字段，必须使用方法来设置类属性，否者无法映射到数据表的字段，只能是一个普通的类属性
    username = db.Column(db.String(100), nullable=False) # 用户名字段
    password = db.Column(db.String(100), nullable=False) # 用户密码字段

# 同步创建
with app.app_context():
    # (1)检查模型：create_all() 会检查 SQLAlchemy ORM 模型以确定哪些表需要被创建
    # (2)创建缺失表：对于每个需要创建的表，create_all() 会在数据库中生成相应的 SQL 语句来创建该表
    db.create_all() # 同步数据库
    
# 路由和视图函数的定义
@app.route('/')
def index():
    return 'Switch paths to operate databases...'

# 添加记录
@app.route('/add/<string:username>/<string:password>')
def add_user(name, passwd):
    user = User(username=name, password=passwd)
    db.session.add(user)
    db.session.commit() # 这里的提交和 MySQL 的事务有关，这里不过多解释，您学了 MySQL 事务就明白为什么需要提交
    return "Add succeed!"

# 查询记录（主键查询）
@app.route('/primary_key_query/<int:id>')
def primary_key_query_user(id):
    a_user = User.query.get(id) # User.query 是继承来的类属性，get() 则是根据主键查找，返回的结果就是 User 对象，可以当作字典来使用
    return f"Query succeed: {a_user.id}-{a_user.username}-{a_user.password}!"

# 查询记录（子句查询）
@app.route('/query/<string:name>')
def query_user(name):
    user_array = User.query.filter_by(username=name) # User.query 是继承来的类属性，get() 则是根据主键查找，但是返回的是一个 Query 对象，相当于一个对象数组，可以做切片操作
    all = {}
    for a_user in user_array:
        all[a_user.username] = a_user.password
    return f"Query succeed: {all}!"

# 修改记录
@app.route('/updata/<string:name>')
def updata(name):
    a_user = User.query.filter_by(username=name).first() # 也可以使用 a_user = User.query.filter_by(username=name)[0] 但是记录不存在时会发生报错
    a_user.password = '271828'
    db.session.commit()
    return f"Updata succeed!"

# 启动 Web 后端服务
if __name__ == '__main__':
    app.run(debug=True)