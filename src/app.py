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

@app.route('/startPrint', methods=['GET', 'POST'])
def startPrint():
    global printer
    if ENABLE_PRINTER:
        printer.startPrint()
    else:
        return "Printer not enabled!"

@app.route('/homeAxes', methods=['GET'])
def homeAxes():
    print("Homing axes!")
    return "Beeping and booping!"

@app.route('/homeRoller', methods=['GET'])
def homeRoller():
    print("Homing roller!")
    return "Let's hope the paper doesn't break..."

@app.route('/abortMotion', methods=['GET'])
def abortMotion():
    print("Aborting motion!")
    return "Warning Will Robinson, Danger! Danger!"

