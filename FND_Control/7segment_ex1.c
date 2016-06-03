#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <stdint.h>

#define SDATA 6 // Serial Input Data
#define STR_CLK 13 // Storage Register Clock (LATCH)
#define SHR_CLK 19 // Shift Register Clock
#define SHR_CLEAR 26 // Shift Register Clear

#define MY_STRING "[JS] : "

void all_clear(void);

void init(void){
	if(wiringPiSetupGpio()==-1){
		fprintf(stderr, MY_STRING "wiringPiSetupGpio() error\n");
		exit(1);
	}
	pinMode(SDATA, OUTPUT);
	pinMode(STR_CLK, OUTPUT);
	pinMode(SHR_CLK, OUTPUT);
	pinMode(SHR_CLEAR, OUTPUT);
	all_clear();
}

void all_clear(){
	digitalWrite(SHR_CLEAR, 0);
	digitalWrite(SHR_CLEAR, 1);
	digitalWrite(STR_CLK, 0);
	digitalWrite(STR_CLK, 1); // latch
}

// unsigned 8 bit int
void set8(uint8_t value){
	int i;
	for(i=0;i<8;i++){
		int mask = 0b1 << i;
		if((value & mask) == 0)
			digitalWrite(SDATA, 0);
		else{
			digitalWrite(SDATA, 1);
			digitalWrite(SHR_CLK, 0);
			digitalWrite(SHR_CLK, 1);
		}
	}
	// latch
	digitalWrite(STR_CLK, 0);
	digitalWrite(STR_CLK, 1);
}

int main(){
	int i;
	uint8_t arr[] = {
		~0b10000000,
		~0b01000000,
		~0b00100000,
		~0b00010000,
		~0b00001000,
		~0b00000100,
		~0b00000010,
		~0b00000001
	};
	init();

	for(i=0;i<8; i++){
		set8(arr[i]);
		delay(1000);
	}
	return 1;
}

	
