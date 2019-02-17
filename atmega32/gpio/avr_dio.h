/*
 * interface.h
 *
 *  Created on: Jul 7, 2018
 *      Author: Eng - Mohamed Bakr
 */

#ifndef AVR_DIO_H_
#define AVR_DIO_H_

#include "../verticle_layer/std_types.h"
#include "../verticle_layer/std_functions.h"
#include "config.h"
#include "config_priv.h"


/// error types
#define ERROR 1
#define SUCCESS 0
#define OUTOFBOUNDS 2
#define INVALID_PORT 3
#define INVALID_DIRECTION 4
#define INVALID_PIN_VALUE 5

/// values of pins
#define OUTPUT 1
#define INPUT 0

u8 GPIO_SetPinDirection(u8 portNumber, u8 pinNumber, u8 direction);

u8 GPIO_SetPinValue(u8 portNumber, u8 pinNumber, u8 value);

u8 GPIO_TGLPinValue(u8 portNumber, u8 pinNumber);

u8 GPIO_GetPinValue(u8 portNumber, u8 pinNumber);

u8 GPIO_GetPinDirection(u8 portNumber, u8 pinNumber);

u8 GPIO_SetPortDirection(u8 portNumber, u8 portDirection);

u8 GPIO_SetPortValue(u8 portNumber, u8 portValue);

u8 GPIO_GetPortValue(u8 portNumber);

u8 GPIO_InitPortsDirection(void);

u8 GPIO_InitPortsValues(void);

u8 GPIO_Init(void);

#endif /* AVR_DIO_H_ */
