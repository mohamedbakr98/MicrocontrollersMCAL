/*
 * adc.c
 *
 * Created: 7/17/2018 7:49:08 PM
 * Author : Eng - Mohamed Bakr
 */ 

#include "std_types.h"
#include "std_functions.h"
#include "adc.h"
#include "Atmega32_registers.h"
#include "config.h"
#include "config_priv.h"


void adc_init(void){
	ADMUX |= ADMUX_VOLTAGE_REF_SELECTION;
	// ADMUX choose left or right adjust
	ADMUX |= ADMUX_LEFT_ADJUST;
	// ADCSRA select prescaler
	ADCSRA |= ADCSRA_PRESCALER_SELECT;
	// enable adc
	ADCSRA |= ADCSRA_ADC_ENABLE;
}

u16 adc_read(Channel channel){
	// check for invalid input	
	if(channel > 7){
		return 1;
	}
	// choose the channel
	switch (channel)
	{
		case channel_0:
			ADMUX  |= CHANNEL0;
			break;
		case channel_1:
			ADMUX  |= CHANNEL1;
		break;
		case channel_2:
			ADMUX  |= CHANNEL2;
		break;
		case channel_3:
			ADMUX  |= CHANNEL3;
		break;
		case channel_4:
			ADMUX  |= CHANNEL4;
		break;
		case channel_5:
			ADMUX  |= CHANNEL5;
		break;
		case channel_6:
			ADMUX  |= CHANNEL6;
		break;
		case channel_7:
			ADMUX  |= CHANNEL7;
		break;
		default:
			// channel_0
			ADMUX  |= CHANNEL0;
	}
	
	// start conversion
	ADCSRA |= ADCSRA_START_CONVERSION;

	// checking for the conversion to finish using polling
	while(ADCSRA & (1<<ADCS));
	
	// get data
	u16 result,temp;
#if LEFT_ADJ == TRUE
	temp = ADCL>>6;
	result = (ADCH<<2) | temp;
#else
	temp = ADCL;
	result = (ADCH<<8) | temp;
#endif // LEFT_ADJ
	return result;
}