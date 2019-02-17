/*
 * lcd.h
 *
 * Created: 8/12/2018 4:14:04 PM
 *  Author: Eng - Mohamed Bakr
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL
#include "../verticle_layer/atmega32_registers.h"
#include "../verticle_layer/std_functions.h"
#include "../verticle_layer/std_types.h"
#include "../gpio/avr_dio.h"

// for dynamic memory alocation
#include <stdlib.h>

#define LCD_dataBus			PORTB
#define LCD_dataBusDir		DDRB
#define LCD_ctrlBus			PORTA
#define LCD_ctrlBusDir		DDRA
#define RS_pin				(7)         //0 for command and 1 for data
#define RW_pin				(2)
#define EN_pin				(6)

#define RW_read				(1)
#define RW_write			(0)
#define RS_command			(0)
#define RS_data				(1)


#define MODE FOUR_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_RAW						(0x80)
#define LCD_BEGIN_AT_SECOND_RAW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

void delay(u16 t);
u16 ready();
void LCD_voidPulseE(u16 t);
void LCD_voidSendCommand(u8 command);
void LCD_voidSendCharacter(u8 character);
void LCD_voidInit(void);
void LCD_voidSendString(char *str);
void LCD_voidClearScreen();
void LCD_voidGotoXY(u8 line,u8 position);
char* intToStr(int x);
u32 intLength(u32 x);
void LCD_voidSendInt(u32 integer);
u8 LCD_u8SendDouble(double d,u8 pointPrecision);

#endif /* LCD_H_ */