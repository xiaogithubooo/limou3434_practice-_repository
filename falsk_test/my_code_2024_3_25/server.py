from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/<int:args>')
def detail(args):
    return render_template('index.html', args_value=args)

if __name__ == '__main__':
    app.run(debug=True)
