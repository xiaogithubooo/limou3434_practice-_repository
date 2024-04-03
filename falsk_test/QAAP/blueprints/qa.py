""" 文件描述
问答逻辑相关蓝图
"""

from flask import Blueprint, render_template, request, g, redirect, url_for
from .forms import QuestionForm, AnswerForm
from models import QuestionModel, UserModel, AnswerModel
from exts import db
from decorators import login_required

# 创建蓝图对象
bp = Blueprint('qa', __name__, url_prefix='/qa')


# 获取主页接口
@bp.route('/index') # 若没有给定 methods 参数则默认为 get 请求, 一般从服务器拿数据用 GET, 提交数据用 POST
def index():
    questions = QuestionModel.query.order_by(QuestionModel.create_time.desc()).all() # 根据时间倒序排序
    return render_template('index.html', questions=questions) # TODO: 这里把文章全部返回了, 有点不太对, 可以考虑分页

# 获取问答主页、发布问答帖子接口
@bp.route('/public_question', methods=['GET', 'POST'])
@login_required # 装饰器内部会检查是否为登陆状态
def public_question():
    if request.method == 'GET':
        return render_template('public_question.html')
    else:
        form = QuestionForm(request.form)
        if form.validate():
            title = form.title.data
            content = form.content.data
            a_question = QuestionModel(title=title, content=content, author=g.user) # 如果这个 g.user 为空(也就是没登录), 这里就会报错
            db.session.add(a_question)
            db.session.commit()
            return redirect('/qa/index')
        else:
            print(form.errors)
            return redirect('/qa/public_question')
        
# 获取文章评论界面接口
@bp.route('/detail/<qa_id>')
def detail(qa_id):
    a_question = QuestionModel.query.get(qa_id)
    a_user = UserModel.query.filter_by(id=a_question.author_id).first()
    return render_template('detail.html', question=a_question, user=a_user)

# 发布评论接口
@bp.route('/public_answer', methods=['POST'])
@login_required
def public_answer():
    form = AnswerForm(request.form)
    if form.validate():
        content = form.content.data
        question_id = form.question_id.data
        answer = AnswerModel(content=content, question_id=question_id, author_id=g.user.id)
        db.session.add(answer)
        db.session.commit()
        return redirect(url_for('qa.detail', qa_id=question_id))
    else:
        print(form.errors)
        return redirect(url_for('qa.detail', qa_id=request.form.get('question_id')))
