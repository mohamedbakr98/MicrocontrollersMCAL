#ifndef CONFIG_PRIV_H
#define CONFIG_PRIV_H

#include "config.h"
#include "../verticle_layer/atmega32_registers.h"
#define PORTA_INIT_VALUE concate(PORTA0,PORTA1,PORTA2,PORTA3,PORTA4,PORTA5,PORTA6,PORTA7)
#define DDRA_INIT_VALUE  concate(DDRA0,DDRA1,DDRA2,DDRA3,DDRA4,DDRA5,DDRA6,DDRA7)

#define PORTB_INIT_VALUE concate(PORTB0,PORTB1,PORTB2,PORTB3,PORTB4,PORTB5,PORTB6,PORTB7)
#define DDRB_INIT_VALUE  concate(DDRB0,DDRB1,DDRB2,DDRB3,DDRB4,DDRB5,DDRB6,DDRB7)

#define PORTC_INIT_VALUE concate(PORTC0,PORTC1,PORTC2,PORTC3,PORTC4,PORTC5,PORTC6,PORTC7)
#define DDRC_INIT_VALUE  concate(DDRC0,DDRC1,DDRC2,DDRC3,DDRC4,DDRC5,DDRC6,DDRC7)

#define PORTD_INIT_VALUE  concate(PORTD0,PORTD1,PORTD2,PORTD3,PORTD4,PORTD5,PORTD6,PORTD7)
#define DDRD_INIT_VALUE   concate(DDRD0,DDRD1,DDRD2,DDRD3,DDRD4,DDRD5,DDRD6,DDRD7)


#define porta 0
#define portb 1
#define portc 2
#define portd 3

#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7





#endif
