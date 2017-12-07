#include "WEMOS_Matrix_LED.h"

uint8_t MLED::allChars[][CHAR_HEIGHT]={
	{0b10101,	//*
	 0b01110,
	 0b11111,
	 0b01110,
	 0b10101},
	{0b01110,	//0
	 0b10011,
	 0b10101,
	 0b11001,
	 0b01110},
	{0b00100,	//1
	 0b01100,
	 0b10100,
	 0b00100,
	 0b11111},
	{0b01110,	//2
 	 0b10001,
	 0b00110,
	 0b01000,
	 0b11111},
	{0b11110,	//3
	 0b00001,
	 0b01110,
	 0b00001,
	 0b11110},
	{0b00110,	//4
	 0b01010,
	 0b11111,
	 0b00010,
	 0b00010},
	{0b11111,	//5
	 0b10000,
	 0b11110,
	 0b00001,
	 0b11110},
	{0b01110,	//6
	 0b10000,
	 0b01110,
	 0b10001,
	 0b01110},
	{0b11111,	//7
	 0b00010,
	 0b00010,
	 0b00100,
	 0b00100},
	{0b01110,	//8
	 0b10001,
	 0b01110,
	 0b10001,
	 0b01110},
	{0b01110,	//9
	 0b10001,
	 0b01111,
	 0b00001,
	 0b11110},
	{0b00100,	//A
	 0b01010,
	 0b11111,
	 0b10001,
	 0b10001},
	{0b11110,	//B
	 0b10001,
	 0b11110,
	 0b10001,
	 0b11110},
	{0b01111,	//C
	 0b10000,
	 0b10000,
	 0b10000,
	 0b01111},
	{0b11110,	//D
	 0b10001,
	 0b10001,
	 0b10001,
	 0b11110},
	{0b11111,	//E
	 0b10000,
	 0b11100,
	 0b10000,
	 0b11111},
	{0b11111,	//F
	 0b10000,
	 0b11100,
	 0b10000,
	 0b10000},
	{0b01111,	//G
	 0b10000,
	 0b10011,
	 0b10001,
	 0b01111},
	{0b10001,	//H
	 0b10001,
	 0b11111,
	 0b10001,
	 0b10001},
	{0b11111,	//I
	 0b00100,
	 0b00100,
	 0b00100,
	 0b11111},
	{0b01110,	//J
	 0b00100,
	 0b00100,
	 0b10100,
	 0b01000},
	{0b10001,	//K
	 0b10010,
	 0b11100,
	 0b10010,
	 0b10001},
	{0b10000,	//L
	 0b10000,
	 0b10000,
	 0b10000,
	 0b11111},
	{0b10001,	//M
	 0b11011,
	 0b10101,
	 0b10001,
	 0b10001},
	{0b10001,	//N
	 0b11001,
	 0b10101,
	 0b10011,
	 0b10001},
	{0b01110,	//O
	 0b10001,
	 0b10001,
	 0b10001,
	 0b01110},
	{0b11110,	//P
	 0b10001,
	 0b11110,
	 0b10000,
	 0b10000},
	{0b01110,	//Q
	 0b10001,
	 0b10001,
	 0b10011,
	 0b01110},
	{0b11110,	//R
	 0b10001,
	 0b11110,
	 0b10100,
	 0b10010},
	{0b01110,	//S
	 0b10000,
	 0b01110,
	 0b00001,
	 0b01110},
	{0b11111,	//T
	 0b00100,
	 0b00100,
	 0b00100,
	 0b00100},
	{0b10001,	//U
	 0b10001,
	 0b10001,
	 0b10001,
	 0b01110},
	{0b10001,	//V
	 0b10001,
	 0b01010,
	 0b01010,
	 0b00100},
	{0b10001,	//W
	 0b10001,
	 0b10101,
	 0b10101,
	 0b01010},
	{0b10001,	//X
	 0b01010,
	 0b00100,
	 0b01010,
	 0b10001},
	{0b10001,	//Y
	 0b10001,
	 0b01010,
	 0b00100,
	 0b00100},
	{0b11111,	//Z
	 0b00010,
	 0b00100,
	 0b01000,
	 0b11111},
	{0b00010,	//(
	 0b00100,
	 0b00100,
	 0b00100,
	 0b00010},
	{0b01000,	//)
	 0b00100,
	 0b00100,
	 0b00100,
	 0b01000},
	{0b00110,	//[
	 0b00100,
	 0b00100,
	 0b00100,
	 0b00110},
	{0b01100,	//]
	 0b00100,
	 0b00100,
	 0b00100,
	 0b01100},
	{0b00010,	//{
	 0b00100,
	 0b01100,
	 0b00100,
	 0b00010},
	{0b01000,	//}
	 0b00100,
	 0b00110,
	 0b00100,
	 0b01000},
	{0b00000,	//+
	 0b00000,
	 0b00100,
	 0b01110,
	 0b00100},
	{0b00000,	//-
	 0b00000,
	 0b00000,
	 0b01110,
	 0b00000},
	{0b00001,	///
	 0b00010,
	 0b00100,
	 0b01000,
	 0b10000},
	{0b10101,	//*
	 0b01110,
	 0b00100,
	 0b01110,
	 0b10101},
	{0b10000,	// backslash
	 0b01000,
	 0b00100,
	 0b00010,
	 0b00001},
	{0b11101,	//%
	 0b10110,
	 0b11111,
	 0b01101,
	 0b10111},
	{0b01110,	//$
	 0b10100,
	 0b01110,
	 0b00101,
	 0b01110},
	{0b01110,	//@
	 0b10001,
	 0b10111,
	 0b10101,
	 0b00111},
	{0b00100,	//|
	 0b00100,
	 0b0010,
	 0b00100,
	 0b00100},
	{0b01010,	//"
	 0b01010,
	 0b00000,
	 0b00000,
	 0b00000},
	{0b00100,	//'
	 0b00100,
	 0b00000,
	 0b00000,
	 0b00000},
	{0b01010,	//#
	 0b11111,
	 0b01010,
	 0b11111,
	 0b01010},
	{0b11100,	//°
	 0b10100,
	 0b11100,
	 0b00000,
	 0b00000},
	{0b01100,	//?
	 0b10010,
	 0b00100,
	 0b00000,
	 0b00100},
	{0b00000,	//.
	 0b00000,
	 0b00000,
	 0b00000,
	 0b00100},
	{0b00100,	//!
	 0b00100,
	 0b00100,
	 0b00000,
	 0b00100},
	{0b11000,	//>
	 0b00110,
	 0b00001,
	 0b00110,
	 0b11000},
	{0b00011,	//<
	 0b01100,
	 0b10000,
	 0b01100,
	 0b00011},
	{0b01100,	//&
	 0b10010,
	 0b01100,
	 0b10010,
	 0b01101},
	{0b01010,	//¨
	 0b00000,
	 0b00000,
	 0b00000,
	 0b00000},
	{0b00000,	// space
	 0b00000,
	 0b00000,
	 0b00000,
	 0b00000},
	{0b00000,	// =
	 0b00000,
	 0b11111,
	 0b00000,
	 0b11111},
	{0b00000,	// :
	 0b00000,
	 0b00100,
	 0b00000,
	 0b00100}
};

MLED::MLED(uint8_t _intensity, byte dataPin, byte clockPin)
{
	this->dataPin = dataPin;
	this->clockPin = clockPin;

	if(_intensity>7)
		intensity=7;
	else
		intensity=_intensity;

	pinMode(dataPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	
	digitalWrite(dataPin, HIGH);
	digitalWrite(clockPin, HIGH);

}

void MLED::display()
{

	for(uint8_t i=0;i<8;i++)
	{
		sendData(i,disBuffer[i]);

		digitalWrite(dataPin, LOW);
  		digitalWrite(clockPin, LOW);
  		digitalWrite(clockPin, HIGH);
  		digitalWrite(dataPin, HIGH);
	}

	sendCommand(0x88|(intensity));
}

void MLED::clear()
{
	for(uint8_t i=0;i<8;i++)
	{
		disBuffer[i]=0x00;
	}

}



void MLED::dot(uint8_t x, uint8_t y, bool draw)
{
	x&=0x07;
	y&=0x07;

	if(draw)
	{
		disBuffer[y]|=(1<<x);
	}
	else
	{
		disBuffer[y]&=~(1<<x);
	}

}

void MLED::sendCommand(byte cmd)
{
  digitalWrite(dataPin, LOW);
  send(cmd);
  digitalWrite(dataPin, HIGH);
}

void MLED::sendData(byte address, byte data)
{
  sendCommand(0x44);
  digitalWrite(dataPin, LOW);
  send(0xC0 | address);
  send(data);
  digitalWrite(dataPin, HIGH);
}

void MLED::send(byte data)
{
  for (int i = 0; i < 8; i++) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, data & 1 ? HIGH : LOW);
    data >>= 1;
    digitalWrite(clockPin, HIGH);
  }
}

#define MIRROR_5BITS(c) ( ((c & 0b00001)<<4) | ((c & 0b00010)<<2) | (c & 0b00100) | ((c & 0b01000)>>2) | ((c & 0b10000)>>4) )

void MLED::drawChar(char character, int x, int y) {
	int index=0;

	if(character>='0' && character<='9') {
		index=1+character-'0';
	} else if(character>='A' && character<='Z') {
		index=11+(character-'A');
	} else {
		index=37;
		switch(character) {
		case '(': index+=0; break;
		case ')': index+=1; break;
		case '[': index+=2; break;
		case ']': index+=3; break;
		case '{': index+=4; break;
		case '}': index+=5; break;
		case '+': index+=6; break;
		case '-': index+=7; break;
		case '/': index+=8; break;
		case '*': index+=9; break;
		case '\\': index+=10; break;
		case '%': index+=11; break;
		case '$': index+=12; break;
		case '@': index+=13; break;
		case '|': index+=14; break;
		case '"': index+=15; break;
		case '\'': index+=16; break;
		case '#': index+=17; break;
		case '°': index+=18; break;
		case '?': index+=19; break;
		case '.': index+=20; break;
		case '!': index+=21; break;
		case '>': index+=22; break;
		case '<': index+=23; break;
		case '&': index+=24; break;
		case '¨': index+=25; break;
		case ' ': index+=26; break;
		case '=': index+=27; break;
		case ':': index+=28; break;
		default: index=0;
		}
	}
	uint8_t* l=allChars[index];
	if(y>(MATRIX_HEIGHT-CHAR_HEIGHT)) y=(MATRIX_HEIGHT-CHAR_HEIGHT);
	if(y<0) y=0;

	uint8_t mask=(x>0)?0b11111000<<x:0b11111000>>(-x);
	for (int i = 0; i < CHAR_HEIGHT; i++) {

		disBuffer[i+y]=(disBuffer[i+y]&~mask)|((x>0)?(MIRROR_5BITS(l[CHAR_HEIGHT-i-1])<<x):(MIRROR_5BITS(l[CHAR_HEIGHT-i-1])>>-x));
	}
}

#define CHAR_SPACE (CHAR_WIDTH+1)
uint32_t MLED::banner(const char* str, unsigned int strLength, uint32_t iC) {
	int c = iC / CHAR_SPACE;
	int x = -(iC % CHAR_SPACE);
	drawChar(str[c % strLength], x, 1);
	drawChar(str[(c + 1) % strLength], x + CHAR_SPACE, 1);
	return ++iC;
}
