/*
 * ADC_cfg.h
 *
 * Created: 3/18/2017 11:56:58 AM
 *  Author: moibrahim
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

     #define ADC_CHANNEL_PROFILE   1
	 #define ADC_CHANNELS_PROFILE  0

     #define ADC_INTERRUPT_ENABLE   1
	 #define PRESCALAR_VALUE		N128
	 #define VREFERENCE_VALUE		AVCC_VOLTAGE
	 #define CHANNEL_NUMBER         ADC0


  typedef enum
  {
	  AREF_VOLTAGE = 0,    // 00
	  AVCC_VOLTAGE,        // 01
	  INTERNAL_VOLTAGE     // 11
  }Reference_Mode;
  
  typedef enum
  {
	  ADC_ON = 0,
	  ADC_OFF
  }ADC_Channel_state;
  
  typedef enum
  {
	  ADC0 = 0,
	  ADC1,
	  ADC2,
	  ADC3,
	  ADC4,
	  ADC5,
	  ADC6,
	  ADC7,
	  LASTCHANNEL
  }Channel_Number;
  
  typedef enum
  {
	 N2 = 0,
	 N4,
	 N8,
	 N16,
	 N32,
	 N64,
	 N128
	  
  }ADC_Prescalar;
  
  extern const ADC_Channel_state Channels[LASTCHANNEL];

#endif /* ADC_CFG_H_ */