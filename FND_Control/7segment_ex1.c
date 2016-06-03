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

	
