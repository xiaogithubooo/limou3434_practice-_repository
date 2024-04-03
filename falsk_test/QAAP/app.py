""" 文件描述
程序启动主逻辑
"""

# flask 相关导入
from flask import Flask, render_template, session, g
import config
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
app.register_blueprint(qa_bp)
app.register_blueprint(auth_bp)

# 设置两个关于 cookie 的钩子函数
# before_request: 在每次请求处理之前都会被调用, 通常用于执行需要在每个请求处理之前进行的操作, 比如身份验证、请求参数...若有多个 before_request 则会按照注册的顺序依次执行。
# before_first_request: 只在应用处理第一个请求之前执行一次, 适用于只需要在应用启动后首次接收到请求时执行的操作, 比如初始化数据库连接、加载配置文件...
# after_request: 在每次请求处理之后都会被调用，但在 before_request 之后, 通常用于执行需要在每个请求处理之后进行的操作, 比如清理资源、记录日志...需要注意 after_request 必须接收一个参数并返回一个响应对象, 否则可能会导致程序错误
# context_processor: 上下文处理器, 在每次渲染模板的时候被执行, 允许定义一些变量并使它们在所有的模板中都可使用
@app.before_request
def my_before_request():
    user_id = session.get('user_id')
    if user_id:
        user = UserModel.query.get(user_id)
        setattr(g, 'user', user)
        # 每个用户使用全局变量 g 时都是隔离开的, 并且它用于存储用户浏览器会话期间的短期记录
        # 在 Flask 框架中，全局变量 g 是线程隔离的, 这意味着每个请求都会有自己独立的 g 对象实例
    else:
        setattr(g, 'user', None)

@app.context_processor
def my_context_processor():
    return {"user": g.user}

# 启动 Web 后端服务
if __name__ == '__main__':
    app.run(debug=True)
