#include "tools.h"

//Functions
int getNumber(void);
void clrNumbers(void);
static void setNumber(int place);

//tools
static bool* visited[10];
// static int* numbers[10];
// static int numtrue = 0;

//////////////////////////////////////////////
int getNumber(void){
	while(1){
		int rn = generateRandomNumber(10);
		if( visited[rn] == false ){
			setNumber(rn);
			// lcd_write_string("number found");
			return rn;
		}
	}
}

//////////////////////////////////////////////
void clrNumbers(void){
	int iter;
	for(iter = 0; iter<10; iter++){
		visited[iter] = false;
	}
	// numtrue = 0;
	return;
}

//////////////////////////////////////////////
static void setNumber(int place){
	visited[place] = true;
	// numtrue = numtrue + 1;
	return;
}

//////////////////////////////////////////////