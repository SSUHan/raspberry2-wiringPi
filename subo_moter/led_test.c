#include <stdio.h>
#include <wiringPi.h>

#define LED_PIN 4 // gpio 23

int main(){
	if(wiringPiSetup() == -1){
		fprintf(stderr, "setup fail..\n");
		return -1;
	}

	pinMode(LED_PIN, OUTPUT);

	while(1){
		digitalWrite(LED_PIN, 1); // on

		delay(1000);

		digitalWrite(LED_PIN, 0); // off

		delay(1000);

	}

	return 0;
}
