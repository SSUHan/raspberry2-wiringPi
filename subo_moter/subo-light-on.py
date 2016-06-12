import RPi.GPIO as GPIO
import time

pin  = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(pin, GPIO.OUT)
p = GPIO.PWM(pin, 50)
p.start(0)
cnt = 0
try:
	p.ChangeDutyCycle(2)
	print "angle : 2"
		
except KeyboardInterrupt:
	p.stop()
GPIO.cleanup()

