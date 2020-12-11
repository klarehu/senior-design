import serial
from threading import Thread

class Printer:
    def __init__(self, port='/dev/ttyACM0'):
        self.serial = serial.Serial(port, timeout=0.1, baudrate=115200)
        self.filepath = None
        self.aborted = False
        self.ready = True
        self.needToWrite = []
        self.rollerPositionF = 0
        self.rollerPositionE = 0
        Thread(target=self.run, args=()).start()

    def run(self):
        read = ''
        while True:
            try:
                read = self.serial.readline().decode('utf-8').strip()
            except:
                print("Error in serial port!")
            if read != '':
                print(read)
            if read == 'OK':
                self.ready = True
            if len(self.needToWrite) != 0:
                toWrite = self.needToWrite.pop(0)
                self.serial.write(toWrite.encode())


    def writeAndWait(self, line):
        self.serial.write(line.encode())
        while True:
            result = self.serial.readline().decode('utf-8').strip()
            print(result)
            if result == 'OK':
                return

    def setFilePath(self, filepath):
        self.filepath = filepath

    def startPrint(self):
        if self.filepath is None:
            return
        self.aborted = False
        file = open(self.filepath, 'r')
        lines = []
        for line in file:
            lines.append(line)
        self.needToWrite = lines

    def abort(self):
        self.aborted = True
        self.needToWrite = []

    def rotateRoller(self):
        self.rollerPositionF -= 30000
        self.rollerPositionE -= 44000
        self.needToWrite.append('G0 F{} E{}\n'.format(self.rollerPositionF, self.rollerPositionE))

if __name__ == '__main__':
    printer = Printer()

    printer.setFilePath('print_files/test.gcode')
