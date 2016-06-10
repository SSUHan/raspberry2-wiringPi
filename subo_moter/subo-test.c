#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <softPwm.h>

int main(){
	int pos = 10;
	int dir = 1;
	if(wiringPiSetup() == -1){
		fprintf(stderr, "setup fail..\n");
		exit(1);
	}

	pinMode(0, OUTPUT);
	digitalWrite(0, LOW);
	softPwmCreate(0,0,200);

	while(1)
	{
		fprintf(stderr, "pos : %d, dir : %d\n", pos, dir);
		pos += dir;
		if(pos < 10 || pos >20)
			dir *= -1;
		delay(190);
	}

	return 0;
}
