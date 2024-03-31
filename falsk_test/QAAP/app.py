""" 文件描述
程序启动主逻辑
"""

from flask import Flask                     # 导入 app 对象
import config                               # 导入配置

from exts import db                         # 导入数据库插件
from flask_migrate import Migrate           # 导入数据库同步, 后续采用三部曲在远端创建数据库，而不是使用 create_all()
from models import UserModel                # 导入 user 数据表

from blueprints.qa import bp as qa_bp       # 导入问答蓝图
from blueprints.auth import bp as auth_bp   # 导入用户蓝图

# 创建 Flask 对象并且做配置
app = Flask(__name__)
app.config.from_object(config)

# 通过 Flask 对象内的数据库相关属性初始数据库操作对象
db.init_app(app)
migrate = Migrate(app, db) # 保证数据库同步

# 绑定蓝图中的视图函数
app.register_blueprint(qa_bp)
app.register_blueprint(auth_bp)

# 启动 Web 后端服务
if __name__ == '__main__':
    app.run(debug=True)