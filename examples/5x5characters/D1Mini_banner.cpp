#include "Arduino.h"


/*
 * Alphabet for Wemos D1 mini with 8x8 LED shield
 *
 * This is my first attempt at making fonts, some turned out
 * great, others not so much.
 *
 * Alphabet was created using the hex vaules from:
 * https://www.riyas.org/2013/12/online-led-matrix-font-generator-with.html
 *
 * Copyright 2017 LeRoy Miller
 *
 * License:
 * Free to do with as you please. Please leave credit in place.
 *
 */

#include <WEMOS_Matrix_LED.h>

MLED mled(5); //set intensity=5

void setup() {
	// put your setup code here, to run once:
}

void shift(boolean left=true) {
	for (int i = 0; i < MATRIX_HEIGHT; i++) {
		uint8_t v=mled.disBuffer[i];
		if(left) {
			v=v<<1;
		} else {
			v=v>>1;
		}
		mled.disBuffer[i]=v;
	}
}

//const char* TEST="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
//const char* TEST="OUVERTURE DU PORTAIL";
const char* TEST="COMMENT VA? # (YES) [NO] {MAYBE} 2+3=5 3*4=12 4/2=2 YES! 4-3=1 \"BOU\" 'GA' HTTP://WWW.XYZ.COM temp:27.3°C C:\\windoze";
int LEN=strlen(TEST);

uint32_t counter=0;

void loop1() {
	mled.clear();
	mled.dot(7,7,true);
	mled.drawChar(TEST[counter%LEN],-1,1);
	mled.display();
	delay(200);
	counter++;
}

void loop() {
	mled.clear();
	counter=mled.banner(TEST,LEN,counter);
	mled.display();
	delay(100);
}

