
#include "lcd.h"

u8 LCD_u8SendDouble(double d,u8 pointPrecision){
	u16 whole,fraction;
	double i = d;
	if(pointPrecision % 10 != 0){
		return 1;
	}
	if(d < 0){
		d = -d;
	}
	whole = d;
	fraction = (d - whole)*pointPrecision; // -3.4 + 3 = -0.4 = -4 
	char *fractionStr = intToStr(fraction);
	char *wholeStr;
	if(i < 0){
		wholeStr = intToStr(-1*whole);
	}else{
		wholeStr = intToStr(whole);
	}
	LCD_voidSendString(wholeStr);
	LCD_voidSendCharacter('.');
	LCD_voidSendString(fractionStr);
	return 0;
}

void LCD_voidSendInt(u32 integer){
	char *str = intToStr(integer);
	LCD_voidSendString(str);
	free(str);
}

char* intToStr(int x){
	int i = x;
	int len = intLength(x);
	char *buffer = (char *) malloc(10);	
	int index = 0;
	if(i < 0){
		i = -i;
		len = intLength(-x);
		buffer[index] = '-';
		index++;
	}
	index += len;  /// jump to the least significant digit
	while(i > 0){
		buffer[--index] = (i % 10) + '0';
		i = i / 10;
	}
	index += len + 1;
	buffer[index] = '\0';
	return buffer;
}
u32 intLength(u32 x){
	u32 i = x;
	u32 len = 0;
	if(i < 0){
		i = -i;
	}
	if( i == 0){
		return 1;
	}
	while(i > 0){
		i = i / 10;
		len++;
	}
	return len;
}

void delay(u16 t){
	int i,j;
	for(i = 0 ; i < t ; i++){
		//do stuff that takes 1ms
		for(j = 0;j < 100;j++){
			 asm("nop");
		}
	}
}
u16 ready(){
	delay(10);
	return 1;
}
void LCD_voidPulseE(u16 t){
	SETBIT(LCD_ctrlBus,EN_pin);
	delay(t);
	CLRBIT(LCD_ctrlBus,EN_pin);
	delay(t);
}
void LCD_voidClearScreen(){
	LCD_voidSendCommand(LCD_CLEAR_SCREEN);
	LCD_voidGotoXY(0,0);
}

void LCD_voidSendCommand(u8 command){
	ready();
	// set RW to write
	CLRBIT(LCD_ctrlBus,RW_pin);
	// set RS to command
	CLRBIT(LCD_ctrlBus,RS_pin);
#if MODE == EIGHT_BIT_MODE
	// clear en?
	CLRBIT(LCD_ctrlBus,EN_pin);
	// set port to command
	LCD_dataBus = command;
	// pulseE
	LCD_voidPulseE(1);
#elif MODE == FOUR_BIT_MODE
	LCD_dataBus = (command&0b11110000); // send upper 4-bits
	SETBIT(LCD_ctrlBus,EN_pin);
	delay(1); // keep E=1 for some time
	CLRBIT(LCD_ctrlBus,EN_pin);
	delay(1); // keep E=0 for some time

	LCD_dataBus=((command&0b00001111)<<4); // send lower 4-bits
	SETBIT(LCD_ctrlBus,EN_pin);
	delay(1); // keep E=1 for some time
	CLRBIT(LCD_ctrlBus,EN_pin);
	delay(1); // keep E=0 for some time
#endif
}
void LCD_voidGotoXY(u8 line,u8 position){
	// check for line
	if(line == 0){
		if(position >= 0 && position < 16){
			LCD_voidSendCommand(LCD_BEGIN_AT_FIRST_RAW + position);
		}
	}else if(line == 1){
		if(position >= 0 && position < 16){
			LCD_voidSendCommand(LCD_BEGIN_AT_SECOND_RAW + position);
		}
	}
}
void LCD_voidSendCharacter(u8 character){
	ready();
	// set RW to write
	CLRBIT(LCD_ctrlBus,RW_pin);
	// set RS to command
	SETBIT(LCD_ctrlBus,RS_pin);
#if MODE == EIGHT_BIT_MODE
	// clear en?
	CLRBIT(LCD_ctrlBus,EN_pin);
	// set port to command
	LCD_dataBus = character;
	// pulseE
	LCD_voidPulseE(1);
#elif MODE == FOUR_BIT_MODE
	LCD_dataBus = (character&0b11110000); // send upper 4-bits
	SETBIT(LCD_ctrlBus,EN_pin);
	delay(1); // keep E=1 for some time
	CLRBIT(LCD_ctrlBus,EN_pin);
	delay(1); // keep E=0 for some time

	LCD_dataBus=((character&0b00001111)<<4); // send lower 4-bits
	SETBIT(LCD_ctrlBus,EN_pin);
	delay(1); // keep E=1 for some time
	CLRBIT(LCD_ctrlBus,EN_pin);
	delay(1); // keep E=0 for some time
#endif
}
void LCD_voidSendString(char *str){
	u8 strlen = 0;
	u8 line1Flag = 0;
	while(*str > 0){
		// check if it's longer than one line
		if(strlen >= 16 && strlen < 32 && line1Flag == 0){
			// move cursor to line 2
			line1Flag = 1;
			LCD_voidGotoXY(1,0);
		}else if(strlen >= 32){
			// clear screen
			LCD_voidClearScreen();
			// start from the beginning
			// zero out the counter
			strlen = 0;
		}
		strlen++;
		LCD_voidSendCharacter(*str++);
	}
}
void LCD_voidInit(void){
	// set databus and ctrlbus data direction
	SET_PORT(LCD_dataBusDir);
	SET_PORT(LCD_ctrlBusDir);
	LCD_voidSendCommand(LCD_FUNCTION_8BIT_2LINES);
	LCD_voidSendCommand(LCD_DISP_ON_CURSOR_BLINK);
	LCD_voidSendCommand(LCD_CLEAR_SCREEN);
	LCD_voidSendCommand(LCD_ENTRY_INC_);
	LCD_voidSendCommand(LCD_BEGIN_AT_FIRST_RAW);
	LCD_dataBus = 0;
	LCD_ctrlBus = 0;
}