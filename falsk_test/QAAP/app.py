""" 文件描述
程序启动主逻辑
"""

from flask import Flask
import config
from exts import db
from blueprints.qa import bp as qa_bp
from blueprints.auth import bp as auth_bp

# 创建 Flask 对象
app = Flask(__name__)

# 导入配置文件内的内容
app.config.from_object(config)

# 通过 Flask 对象初始数据库操作对象
db.init_app(app)

# 绑定蓝图中的视图函数
app.register_blueprint(qa_bp)
app.register_blueprint(auth_bp)

# 启动 Web 后端服务
if __name__ == '__main__':
    app.run(debug=True)