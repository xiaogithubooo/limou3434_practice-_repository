from flask import Flask, render_template

app = Flask(__name__)

# 路由定义
@app.route('/')
def father():
    return render_template('father.html')

@app.route('/child_1')
def child_1():
    return render_template('child_1.html')

@app.route('/child_2')
def child_2():
    return render_template('child_2.html')

@app.route('/child_3')
def child_3():
    return render_template('child_3.html')

if __name__ == '__main__':
    app.run(debug=True)
