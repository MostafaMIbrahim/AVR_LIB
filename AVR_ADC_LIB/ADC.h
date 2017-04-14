/*
 * ADC.h
 *
 * Created: 3/17/2017 11:26:11 AM
 *  Author: moibrahim
 */ 


#ifndef ADC_H_
#define ADC_H_

   #include "ADC_cfg.h"

extern void ADC_Init(void);
extern void ADC_start(void);
extern uint8 ADC_Read_Channels(uint16* channel_result);
extern uint16 ADC_Read(void);

#endif /* ADC_H_ */