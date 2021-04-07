#include <at89c5131.h>
// #include "lcd.h"	//Header file with LCD interfacing functions
#include "serial.c"	//C file with UART interfacing functions
//game related
#include "words.c"
#include "numbers.c"
#include "tools.h"

int numbers[10];
unsigned char* word_list[10];
unsigned int score = 0;
unsigned int HIGHSCORE = 0;

void resetGame(void){
	int i;

	for(i = 0; i<10; i++){
		numbers[i] = -1;
		word_list[i] = "";
	}

	// resetState();
	clrNumbers();

	score = 0;
}

void writeWordToLCD(unsigned int index){
	lcd_cmd(0x80);
	lcd_write_string(word_list[index]);
	lcd_write_string(" ");
}

void writeNumToLCD(unsigned int index){
	lcd_cmd(0x85);
	lcd_write_char(48 + numbers[index]);
}

void displayResults(void){
	lcd_init();
	if(HIGHSCORE < score) HIGHSCORE = score;
	lcd_cmd(0x80);
	lcd_write_string("Score:");
	lcd_cmd(0x8C);
	lcd_write_char(48 + score);
	lcd_cmd(0xC0);
	lcd_write_string("HIGHSCORE:");
	lcd_cmd(0xCC);
	lcd_write_char(48 + HIGHSCORE);
	msdelay(3000);
}

void main(void){
	unsigned int i;
	// int time;
	//Init stuff
	lcd_init();	
	uart_init();
	srand(0);
	beginGameState();
	//game
	while(1){
		resetGame();

		//print stuff
		lcd_init();
		for (i = 0; i < 10; i++){
			word_list[i] = get_word();
			numbers[i] = getNumber();
			writeWordToLCD(i);
			writeNumToLCD(i);
			msdelay(1000);
		}
		//get ready
		lcd_init();
		lcd_write_string("Get Ready");
		msdelay(1000);

		//get stuff
		for (i = 0; i < 10; ++i){
			unsigned char ch, ascii;
			lcd_init();
			writeWordToLCD(i);
			ch = receive_char();
			ascii = numbers[i] + 48;
			if(ascii == ch) score = score + 1;
		}

		displayResults();
		
	}
}