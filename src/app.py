from flask import Flask, Response, render_template, request
from constants import ENABLE_PRINTER

printer = None
if ENABLE_PRINTER:
    from printer import Printer
    # from button import Button
    printer = Printer()
    # button = Button(callback=print)

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
    if ENABLE_PRINTER:
        printer.needToWrite.append('H0')
    return "Beeping and booping!"

@app.route('/homeRoller', methods=['GET'])
def homeRoller():
    print("Homing roller!")
    if ENABLE_PRINTER:
        printer.rotateRoller()
    return "Let's hope the paper doesn't break..."

@app.route('/abortMotion', methods=['GET'])
def abortMotion():
    print("Aborting motion!")
    if ENABLE_PRINTER:
        printer.abort()
    return "Warning Will Robinson, Danger! Danger!"

@app.route('/printSVG', methods=['GET'])
def printSVG():
    print("Printing SVG!")
    if ENABLE_PRINTER:
        printer.setFilePath('print_files/test.gcode')
        printer.startPrint()
    return "Now printing SVG..."

@app.route('/printPattern', methods=['GET'])
def printPattern():
    print("Printing Pattern!")
    if ENABLE_PRINTER:
        printer.setFilePath('print_files/out.gcode')
        printer.startPrint()
    return "Now printing pattern..."
