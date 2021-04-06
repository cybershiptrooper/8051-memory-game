#ifndef TOOL_H
#define TOOL_H

#include <stdlib.h>

typedef enum {true, false} bool;

int generateRandomNumber(int max){
	return rand()%max;
	// return 1;
}

#endif