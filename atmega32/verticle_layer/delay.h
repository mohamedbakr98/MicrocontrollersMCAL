/*
 * delay.h
 *
 *  Created on: Aug 15, 2018
 *  Author:  Mohamed Bakr
 */

#ifndef DELAY_H_
#define DELAY_H_
#include "std_types.h"

// 1MHz clock means 1000000 cycles per second.
// So 1 cycle equals 1/1000000 seconds or 1us.
// To get 1 second delay, you need 1000000 cycles of 1us,
// so it means that you have to DELAY_MS(1000) which mean number of cycles (1000000/1000)*1000 =1000000 cycles = 1 sec
// the "NOP" takes 1 Cycle only



#define clock   8000000
#define error_ratio 30
u32 DelayCount;

#define DELAY_MS(x) \
		for( DelayCount = ((clock/1000)*x/error_ratio); DelayCount >0; DelayCount--)\
			{\
				__asm("NOP");\
			}




#endif /* DELAY_H_ */