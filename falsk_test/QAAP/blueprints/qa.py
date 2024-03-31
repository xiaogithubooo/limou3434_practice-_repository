""" 文件描述
问答逻辑相关蓝图
"""

from flask import Blueprint             
from flask import render_template

# 创建蓝图对象
bp = Blueprint('qa', __name__, url_prefix='/')