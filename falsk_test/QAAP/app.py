""" 文件描述
程序启动主逻辑
"""


# flask 相关导入
from flask import Flask
import config
from flask import render_template
# exts 插件导入
from exts import db, mail, migrate
# 视图函数相关导入
from blueprints.qa import bp as qa_bp       # 导入问答蓝图
from blueprints.auth import bp as auth_bp   # 导入用户蓝图
# ORM 模型导入
from models import UserModel


# 创建 Flask 对象并且做配置
app = Flask(__name__)
app.config.from_object(config)

# 通过 Flask 对象内的数据库相关属性初始数据库操作对象
db.init_app(app)
migrate.init_app(app, db)
mail.init_app(app)

# 绑定蓝图中的视图函数
@app.route('/') # 若没有给定 methods 参数则默认为 get 请求, 一般从服务器拿数据用 GET, 提交数据用 POST
def index():
    return render_template('index.html')
app.register_blueprint(qa_bp)
app.register_blueprint(auth_bp)

# 启动 Web 后端服务
if __name__ == '__main__':
    app.run(debug=True)
