#include "tools.h"
// #include <stdio.h>
//Functions
static void updateState(void);
static unsigned char* getString(void);

unsigned char* get_word(void);
void beginGameState(void);
//tools
static int state = 0;

//////////////////////////////////////////////
unsigned char* get_word(void){
	unsigned char* s = getString();
	updateState();
	return s;
}

//////////////////////////////////////////////
//state functions
static void updateState(void){
	// state = state + 1;
	unsigned int b0, b3, rs;
    b0 = (state<<4)&(16);
    b3 = (state<<1)&(16);
    rs = (state>>1);
    state = (rs)|(b0^b3);
}

void beginGameState(void){
	state = generateRandomNumber(31)+1;//between 1 to 31
}

//////////////////////////////////////////////
static unsigned char* getString(){
	switch(state-1){
		case 0: return "king";
		case 1: return "idea";
		case 2: return "good";
		case 3: return "left";
		case 4: return "exit";
		case 5: return "taxi";
		case 6: return "chef";
		case 7: return "lava";
		case 8: return "cafe";
		case 9: return "logo";

		case 10: return "east";
		case 11: return "mars";
		case 12: return "next";
		case 13: return "news";
		case 14: return "echo";
		case 15: return "game";
		case 16: return "fuel";
		case 17: return "gate";
		case 18: return "flex";
		case 19: return "raja";

		case 20: return "road";
		case 21: return "toad";
		case 22: return "ruby";
		case 23: return "side";
		case 24: return "type";
		case 25: return "pipe";
		case 26: return "snow";
		case 27: return "slow";
		case 28: return "blow";
		case 29: return "fuji";

		case 30: return "pogo";

		default: return "fail";
	};
}