from threading import Thread
import RPi.GPIO as GPIO
import time

class Button:
	def __init__(self, callback, buttonInput=17, ledOutput=18):
		self.stopped = False
		self.buttonInput = buttonInput
		self.ledOutput = ledOutput
		self.callback = callback
		GPIO.setmode(GPIO.BCM)
		GPIO.setup(self.buttonInput, GPIO.IN)
		GPIO.setup(self.ledOutput, GPIO.OUT)
		GPIO.output(self.ledOutput, GPIO.HIGH)
		Thread(target=self.run, args=()).start()

	def run(self):
		while not self.stopped:
			if GPIO.input(self.buttonInput):
				self.callback()
			time.sleep(0.1)

	def stop(self):
		self.stopped = True
