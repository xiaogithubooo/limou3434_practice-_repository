""" 文件描述
问答逻辑相关蓝图
"""

from flask import Blueprint             
from flask import render_template


bp = Blueprint(
    'qa', # 设置蓝图名
    __name__, # 设置传入当前文件名
    url_prefix='/' # 设置 url 前缀，之后所有的视图函数都必须以该前缀为开头
) # 之后的视图函数都使用这个 bp 对象来创建