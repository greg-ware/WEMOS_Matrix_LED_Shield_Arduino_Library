
#ifndef __WEMOS_Matrix_LED_H
#define __WEMOS_Matrix_LED_H


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define MATRIX_HEIGHT 8
#define MATRIX_WIDTH 8

#define CHAR_WIDTH 5
#define CHAR_HEIGHT 5

class MLED {
public:
	MLED(uint8_t _intensity=4, byte dataPin=D7, byte clockPin=D5);
	void display();
	void clear();
	void dot(uint8_t x, uint8_t y, bool draw=1);
	void drawChar(char character, int x=0, int y=0);
	uint32_t banner(const char* str, unsigned int strLength, uint32_t counter);

	volatile uint8_t disBuffer[MATRIX_HEIGHT]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	uint8_t intensity;

protected:
	void sendCommand(byte led);
	void sendData(byte add, byte data);
	void send(byte data);

	byte dataPin;
	byte clockPin;

	static uint8_t allChars[][CHAR_HEIGHT];

};

#endif
