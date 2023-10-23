from flask import Flask, request, jsonify

app = Flask(__name)

@app.route('/')
def teste_c6():
    return open('teste_c6.html').read()

@app.route('/run-python', methods=['POST'])
def run_python():
    try:
        code = request.json['code']
        result = eval(code)
        return str(result)
    except Exception as e:
        return "Erro: " + str(e)

if __name__ == '__main__':
    app.run()
