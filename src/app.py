from flask import Flask, Response, render_template, request
from constants import ENABLE_PRINTER

printer = None
if ENABLE_PRINTER:
    from printer import Printer
    printer = Printer().start()

app = Flask(__name__)

@app.route('/')
def index():
    return render_template("index.html")

@app.route('/start_print', methods=['GET', 'POST'])
def start_print():
    global printer
    if ENABLE_PRINTER:
        printer.start_print()
    else:
        return "Printer not enabled!"
