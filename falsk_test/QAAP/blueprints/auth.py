""" 文件描述
用户授权逻辑相关蓝图
"""

from flask import Blueprint
bp = Blueprint(
    'auth', # 设置蓝图名
    __name__, # 设置传入当前文件名
    url_prefix='/auth' # 设置 url 前缀，之后所有的视图函数都必须以该前缀为开头
) # 之后的视图函数都使用这个 bp 对象来创建

@bp.route('/login')
def login():
    pass