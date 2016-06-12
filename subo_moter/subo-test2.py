import RPi.GPIO as GPIO
import time

pin  = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(pin, GPIO.OUT)
p = GPIO.PWM(pin, 50)
p.start(0)
cnt = 0
try:
	while True:
		p.ChangeDutyCycle(1)
		print "angle : 1"
		time.sleep(2)
		p.ChangeDutyCycle(2)
		print "angle : 2"
		time.sleep(2)
		p.ChangeDutyCycle(3)
		print "angle : 3"
		time.sleep(2)
		p.ChangeDutyCycle(4)
		print "angle : 4"
		time.sleep(2)
		p.ChangeDutyCycle(5)
		print "angle : 5"
		time.sleep(2)
		p.ChangeDutyCycle(6)
		print "angle : 6"
		time.sleep(2)
		p.ChangeDutyCycle(7)
		print "angle : 7"
		time.sleep(2)
		p.ChangeDutyCycle(8)
		print "angle : 8"
		time.sleep(2)
#	cnt = cnt +1
#p.ChangeDutyCycle(9)
#		print "angle : 9"
#		time.sleep(2)
		
except KeyboardInterrupt:
	p.stop()
GPIO.cleanup()

