from flask import Flask, request, jsonify, render_template

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html') # 渲染 templates 文件夹下的 index.html 页面

@app.route('/get_hello', methods=['POST']) # 用户点击按钮后，通过 fetch() 跳转到下面的视图函数
def get_hello():
    data = request.get_json()  # 获取客户端发送的 JSON 数据
    message = data['name'] + '3434' # 加工用户发送过来的数据
    return jsonify({'message': message}) # 以 JSON 的显示转回客户端

if __name__ == '__main__':
    app.run(debug=True)
