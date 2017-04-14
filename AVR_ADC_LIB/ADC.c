/*
 * ADC.c
 *
 * Created: 3/17/2017 11:25:57 AM
 *  Author: moibrahim
 */ 
#include <avr/interrupt.h>
#include "Types.h"
#include "Util.h"
#include "memmaps.h"
#include "ADC.h"

static void ADC_ClearReg(void);
static void ADC_Configure_Reference(uint8 Reference_Mode);
static void ADC_Channel_Selection(Channel_Number channel);
static void ADC_Configure_Prescalar(uint8 Prescalar);
static void ADC_Enable(void);
static void ADC_Disable(void);
static uint8 ADC_get_flag(void);
static void ADC_Enable_ISR(void);
static void ADC_Disable_ISR(void);
static void Enable_Global_ISR(void);
static void Disable_Global_ISR(void);
static void ADC_Enable_ADATE(void);
static void ADC_Disable_ADATE(void);
static void ADC_Start_Conversion(Channel_Number channel);

static uint16 result[LASTCHANNEL];
static uint16 ADC_Result;
static Channel_Number channel;
static uint8 count = 0;
/**  Init ADC Driver**/
void ADC_Init(void)
{
	ADC_Configure_Reference(VREFERENCE_VALUE);
	ADC_Configure_Prescalar(PRESCALAR_VALUE);
	
	#if ADC_CHANNEL_PROFILE==1
	   ADC_Channel_Selection(CHANNEL_NUMBER);
	#endif
	
	#if ADC_CHANNELS_PROFILE==1
	int i;
	for(i = 0; i<LASTCHANNEL; i++)
	{
		if(Channels[i] == ADC_ON) 
		{
			channel = i;
			break;
		}	
	}
	ADC_Channel_Selection(channel);
	#endif
	
	ADC_Enable();
	ADC_Enable_ISR();
	Enable_Global_ISR();

}
/**  Clear ADC Register**/
void ADC_ClearReg(void)
{
	CLEAR_REG(ADMUX);
	CLEAR_REG(ADCSRA);
//	CLEAR_REG(ADCSRB);	
}
/**  This function is used to select the refernce voltage for ADC**/
void ADC_Configure_Reference(Reference_Mode mode)
{
	switch (mode)
	{
		case AREF_VOLTAGE:
    	   CLEAR_BIT(ADMUX,REFS0);
    	   CLEAR_BIT(ADMUX,REFS1);
		break;
		
		case AVCC_VOLTAGE:
		  SET_BIT(ADMUX,REFS0);
		  CLEAR_BIT(ADMUX,REFS1);
		break;
		
	    case INTERNAL_VOLTAGE:
		  SET_BIT(ADMUX,REFS0);
		  SET_BIT(ADMUX,REFS1);
		break;
	}
}

/**  This function is used to select the the cahnnel voltage for ADC**/
void ADC_Channel_Selection(Channel_Number channel)
{
	ASSIGN_REG(ADMUX, (GET_NIBBLE_HH(ADMUX)|GET_NIBBLE_LL(channel)) );
}

/**  Select the Prescalar
 * 2,4,8,16,32,64,128
 * **/
void ADC_Configure_Prescalar(ADC_Prescalar Prescalar)
{
	switch(Prescalar)
	{
		case N2:
		   SET_BIT(ADCSRA,ADPS0);
		   CLEAR_BIT(ADCSRA,ADPS1);
		   CLEAR_BIT(ADCSRA,ADPS2);
		break;
		case N4:
		   CLEAR_BIT(ADCSRA,ADPS0);
		   SET_BIT(ADCSRA,ADPS1);
		   CLEAR_BIT(ADCSRA,ADPS2);
		break;
		case N8:
		   SET_BIT(ADCSRA,ADPS0);
		   SET_BIT(ADCSRA,ADPS1);
		   CLEAR_BIT(ADCSRA,ADPS2);
		break;
		case N16:
		   CLEAR_BIT(ADCSRA,ADPS0);
		   CLEAR_BIT(ADCSRA,ADPS1);
		   SET_BIT(ADCSRA,ADPS2);
		break;
		case N32:
		   SET_BIT(ADCSRA,ADPS0);
		   CLEAR_BIT(ADCSRA,ADPS1);
		   SET_BIT(ADCSRA,ADPS2);
		break;
		case N64:
		   CLEAR_BIT(ADCSRA,ADPS0);
		   SET_BIT(ADCSRA,ADPS1);
		   SET_BIT(ADCSRA,ADPS2);
		break;
		case N128:
		   SET_BIT(ADCSRA,ADPS0);
		   SET_BIT(ADCSRA,ADPS1);
		   SET_BIT(ADCSRA,ADPS2);
		break;
	}
}

/**  Enable ADC **/
void ADC_Enable(void)
{
	SET_BIT(ADCSRA,ADEN);
}

/**  Disable ADC **/
void ADC_Disable(void)
{
	CLEAR_BIT(ADCSRA,ADEN);
}

/**To start the first conversion**/
void ADC_start(void)
{
	SET_BIT(ADCSRA,ADSC);
}

/*Get the status of flag ADC*/
uint8 ADC_get_flag(void)
{
	return(GET_BIT(ADCSRA,ADIF));
}

/*Enable ADC ISR*/
void ADC_Enable_ISR(void)
{
	SET_BIT(ADCSRA ,ADIE);
}

/*Disable ADC ISR*/
void ADC_Disable_ISR(void)
{
	CLEAR_BIT(ADCSRA ,ADIE);
}

/*Enable ADATE(ADC Auto Trigger Source) mode*/
void ADC_Enable_ADATE(void)
{
	SET_BIT(ADCSRA ,ADATE);
}

/*Disable ADATE(ADC Auto Trigger Source)*/
void ADC_Disable_ADATE(void)
{
	CLEAR_BIT(ADCSRA ,ADATE);
}
/**To Start Conversion ADC channel**/
void ADC_Start_Conversion(Channel_Number channel)
{
   ADC_Channel_Selection(channel);
   ADC_start();
}
/**To read from ADC channel**/
uint16 ADC_Read(void)
{	
   #if ADC_INTERRUPT_ENABLE==0
     while (ADC_get_flag());
   #endif
   return ADC_Result;
}
/*To Read Multi-ADC Channel in same time*/
uint8 ADC_Read_Channels(uint16* channel_result)
{
	for(int i=0;i<LASTCHANNEL;i++)
	{
	  channel_result[i] = result[i];
	}
	return count;
}
/**  The Global Interrupt Enable bit must be set for the interrupts to be enabled
 * This function enable the global interrupt
 * **/
void Enable_Global_ISR(void)
{
	sei();
}
/**  The Global Interrupt Enable bit must be set for the interrupts to be enabled
 * This function disable the global interrupt
 * **/
void Disable_Global_ISR(void)
{
  cli();	
}

ISR(ADC_vect)
{
	uint8 theLow = ADCL;
	ADC_Result = ADCH<<8 | theLow;
	#if ADC_CHANNELS_PROFILE==1
	  result[channel] = ADC_Result;
	  for(int i = channel;i<LASTCHANNEL;i++)
	  {
		  if(Channels[i] == ADC_ON)
		  {
			  channel = i;
			  ADC_Start_Conversion(channel);
			  break;
		  }
	  }
	  count++;
	#endif
}

