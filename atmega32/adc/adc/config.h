/*
 * reg.h
 *
 *  Created on: Jul 7, 2018
 *      Author: Eng - Mohamed Bakr
 */

#ifndef CONFIG_H_
#define CONFIG_H_



#define TRUE  1
#define FALSE 0

#define ADC_ENABLE TRUE

//////////////////////////////////////////////////////////////////////////
#define ADMUX_VOLTAGE_REF_SELECTION    AVCC_EXTERNAL_CAP_AREF       // select ref voltage

#define AREF_INTERNAL_VREF_OFF	0b00000000
#define AVCC_EXTERNAL_CAP_AREF	0b01000000
#define INTERAL_VOLTAGE_REF     0b11000000

//////////////////////////////////////////////////////////////////////////

// select left or right adjust
#define LEFT_ADJ TRUE

//////////////////////////////////////////////////////////////////////////

//#define ADMUX_SELECT_CHANNEL   // must add channel

#define CHANNEL0 0b00000000
#define CHANNEL1 0b00000001
#define CHANNEL2 0b00000010
#define CHANNEL3 0b00000011
#define CHANNEL4 0b00000100
#define CHANNEL5 0b00000101
#define CHANNEL6 0b00000110
#define CHANNEL7 0b00000111


#define ENABLE_AUTO_TRIGGER FALSE

#if ENABLE_AUTO_TRIGGER == TRUE

#define SFIOR_AUTO_TRIGGER_MODE FREE_RUNNING_MODE

#define FREE_RUNNING_MODE					 0b00000000
#define ANALOG_COMPRATOR					 0b00100000
#define EXTERNAL_INTERRUPT_REQUEST0			 0b01000000
#define TIMER0_COMPARE_COMPARE_MATCH         0b01100000
#define TIMER0_OVERFLOW						 0b10000000
#define TIMER1_COMPARE_MATCH_B				 0b10100000
#define TIMER1_OVERFLOW                      0b11000000
#define TIMER1_CAPTURE_EVENT                 0b11100000


#endif // ENABLE_AUTO_TRIGGER


#define ADCSRA_PRESCALER_SELECT DIV_FACTOR_128

#define DIV_FACTOR_2	0b00000001
#define DIV_FACTOR_4	0b00000010
#define DIV_FACTOR_8	0b00000011
#define DIV_FACTOR_16	0b00000100
#define DIV_FACTOR_32	0b00000101
#define DIV_FACTOR_64	0b00000110
#define DIV_FACTOR_128	0b00000111


#endif /* CONFIG_H_ */
