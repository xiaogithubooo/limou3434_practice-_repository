""" 文件描述
问答逻辑相关蓝图
"""

from flask import Blueprint             
from flask import render_template

# 创建蓝图对象
bp = Blueprint('qa', __name__, url_prefix='/qa')
@bp.route('index') # 若没有给定 methods 参数则默认为 get 请求, 一般从服务器拿数据用 GET, 提交数据用 POST
def index():
    return render_template('index.html')
