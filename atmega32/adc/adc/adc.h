/*
 * adc.h
 *
 * Created: 7/17/2018 7:51:46 PM
 *  Author: Eng - Mohamed Bakr
 */ 


#ifndef ADC_H_
#define ADC_H_

#define ADCS 6
enum channelNum {channel_0, channel_1, channel_2,channel_3 ,channel_4 ,channel_5 ,channel_6 ,channel_7};
typedef enum channelNum Channel;


void adc_init(void);
u16 adc_read(Channel channel);

#endif /* ADC_H_ */