/*
 * interface.c
 *
 *  Created on: Jul 7, 2018
 *      Author: Eng - Mohamed Bakr
 */

#include "avr_dio.h"

u8 GPIO_TGLPinValue(u8 portNumber, u8 pinNumber){

	/// Boundary checking:
	if(pinNumber > 8){
		return OUTOFBOUNDS;
	}

	switch(portNumber){
	case porta:
		TOGGLEBIT(PORTA,pinNumber);
		break;
	case portb:
			TOGGLEBIT(PORTB,pinNumber);
			break;
	case portc:
			TOGGLEBIT(PORTC,pinNumber);
			break;
	case portd:
			TOGGLEBIT(PORTD,pinNumber);
			break;
	default:
		return INVALID_PORT;
		break;
	}
	return SUCCESS;
}

u8 GPIO_GetPinDirection(u8 portNumber, u8 pinNumber){
	/// Boundary checking:
		if(pinNumber > 8){
			return OUTOFBOUNDS;
	}
	u8 result;
	switch(portNumber){
			case porta:
				result = GETBIT(DDRA,pinNumber);
				break;
			case portb:
				result = GETBIT(DDRB,pinNumber);
				break;
			case portc:
				result = GETBIT(DDRC,pinNumber);
				break;
			case portd:
				result = GETBIT(DDRD,pinNumber);
				break;
			default:
				result = INVALID_PORT;
				break;
		}
	return result;
}

u8 GPIO_InitPortsValues(void){
	GPIO_SetPortValue(porta, PORTA_INIT_VALUE);
	GPIO_SetPortValue(portb, PORTB_INIT_VALUE);
	GPIO_SetPortValue(portc, PORTC_INIT_VALUE);
	GPIO_SetPortValue(portd, PORTD_INIT_VALUE);

	return SUCCESS;
}

u8 GPIO_InitPortsDirection(void){
	GPIO_SetPortDirection(porta, DDRA_INIT_VALUE);
	GPIO_SetPortDirection(portb, DDRB_INIT_VALUE);
	GPIO_SetPortDirection(portc, DDRC_INIT_VALUE);
	GPIO_SetPortDirection(portd, DDRD_INIT_VALUE);
	return SUCCESS;
}

u8 GPIO_Init(void){
	GPIO_InitPortsValues();
	GPIO_InitPortsDirection();
	return SUCCESS;
}

u8 GPIO_SetPinDirection(u8 portNumber, u8 pinNumber, u8 direction){

	/// check direction boundaries
	if(direction != OUTPUT && direction != INPUT){
		return INVALID_DIRECTION;
	}

	/// check pinNumber boundaries
	if(pinNumber > 8){
		return OUTOFBOUNDS;
	}

	switch(portNumber){
		case porta:
			if(direction == 0){
				CLRBIT(DDRA,pinNumber);
			}else{
				SETBIT(DDRA,pinNumber);
			}
			break;
		case portb:
			if(direction == 0){
				CLRBIT(DDRB,pinNumber);
			}else{
				SETBIT(DDRB,pinNumber);
			}
			break;
		case portc:
			if(direction == 0){
				CLRBIT(DDRC,pinNumber);
			}else{
				SETBIT(DDRC,pinNumber);
			}
			break;
		case portd:
			if(direction == 0){
				CLRBIT(DDRD,pinNumber);
			}else{
				SETBIT(DDRD,pinNumber);
			}
			break;
		default:
			return INVALID_PORT;
			break;
	}
	return SUCCESS;
}

u8 GPIO_SetPinValue(u8 portNumber, u8 pinNumber, u8 value){

	/// check direction boundaries
	if(value != HIGH && value != LOW){
		return INVALID_PIN_VALUE;
	}

	/// check pinNumber boundaries
	if(pinNumber > 8){
		return OUTOFBOUNDS;
	}

	switch(portNumber){
		case porta:
			if(value == 0){
				CLRBIT(PORTA,pinNumber);
			}else{
				SETBIT(PORTA,pinNumber);
			}
			break;
		case portb:
			if(value == 0){
				CLRBIT(PORTB,pinNumber);
			}else{
				SETBIT(PORTB,pinNumber);
			}
			break;
		case portc:
			if(value == 0){
				CLRBIT(PORTC,pinNumber);
			}else{
				SETBIT(PORTC,pinNumber);
			}
			break;
		case portd:
			if(value == 0){
				CLRBIT(PORTD,pinNumber);
			}else{
				SETBIT(PORTD,pinNumber);
			}
			break;
		default:
			return INVALID_PORT;
			break;
	}
	return SUCCESS;
}

u8 GPIO_GetPinValue(u8 portNumber, u8 pinNumber){

	/// check pinNumber boundaries
	if(pinNumber > 8){
		return OUTOFBOUNDS;
	}
	u8 result;
	switch(portNumber){
			case porta:
				result = GETBIT(PORTA,pinNumber);
				break;
			case portb:
				result = GETBIT(PORTB,pinNumber);
				break;
			case portc:
				result = GETBIT(PORTC,pinNumber);
				break;
			case portd:
				result = GETBIT(PORTD,pinNumber);
				break;
			default:
				result = INVALID_PORT;
				break;
		}
	return result;
}

u8 GPIO_SetPortDirection(u8 portNumber, u8 portDirection){

	switch(portNumber){
			case porta:
				DDRA = portDirection;
				break;
			case portb:
				DDRB = portDirection;
				break;
			case portc:
				DDRC = portDirection;
				break;
			case portd:
				DDRD = portDirection;
				break;
			default:
				return INVALID_PORT;
				break;
	}
	return SUCCESS;
}

u8 GPIO_SetPortValue(u8 portNumber, u8 value){

	switch(portNumber){
				case porta:
					PORTA = value;
					break;
				case portb:
					PORTB = value;
					break;
				case portc:
					PORTC = value;
					break;
				case portd:
					PORTD = value;
					break;
				default:
					return INVALID_PORT;
					break;
	}
	return SUCCESS;
}

u8 GPIO_GetPortValue(u8 portNumber){
	u8 result;
	switch(portNumber){
			case porta:
				result = PORTA;
				break;
			case portb:
				result = PORTB;
				break;
			case portc:
				result = PORTC;
				break;
			case portd:
				result = PORTD;
				break;
			default:
				/// COULDN'T ADD INVALID_PORT DUE TO COLLISION POTENTIAL
				break;
		}
	return result;
}
