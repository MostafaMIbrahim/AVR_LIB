/*
 * TIMER0.c
 *
 * Created: 2/20/2017 2:46:52 AM
 *  Author: moibrahim
 */
#include <avr/interrupt.h> 
#include "Types.h"
#include "Util.h"
#include "TIMER0.h"


static uint16 count;
static CLK_Mode prescaler;
/*******************************************************************************************/
  static void Timer0_ClearReg(void);
  static void TIMER0_Configure_Mode(TMR0_Mode mode, OUT_mode out);
  static void TIMER0_Configure_CLK(CLK_Mode clk_mode);
  static void TIMER0_set_timer_value(uint8 value);
  static void TIMER0_set_out_compareA_value(uint8 value);
  static void TIMER0_set_out_compareB_value(uint8 value);
  static void TIMER0_Overflow_Enable_ISR(void);
  static void TIMER0_Overflow_Disable_ISR(void);
  static void TIMER0_OutcmpareA_Enable_ISR(void);
  static void TIMER0_OutcmpareA_Disable_ISR(void);
  static void TIMER0_OutcmpareB_Enable_ISR(void);
  static void TIMER0_OutcmpareB_Disable_ISR(void);
  static uint8 TIMER0_get_overflow_flag(void);
  static uint8 TIMER0_get_outcompareA_flag(void);
  static uint8 TIMER0_get_outcompareB_flag(void);
  static void TIMER0_clear_overflow_flag(void);
  static void TIMER0_clear_outcompareA_flag(void);
  static void TIMER0_clear_outcompareB_flag(void);
  static void Enable_Global_ISR(void);
  static void Disable_Global_ISR(void);
  static void ConfigReg(void);
/**************************************************************************/
/**  Initialization of Registers of Timer 0 and run**/
void Timer0_InitAndRun(void)
{
	Timer0_ClearReg();
	ConfigReg();
	#ifdef INT_PRESCALER
	if(count)
	{
		TIMER0_Configure_Mode(TIMER_MODE, OUT_MODE);    // Set CTC mode with normal port
		TIMER0_Configure_CLK(prescaler);	
		TIMER0_set_out_compareA_value(count);       // Set OCR0A
		TIMER0_OutcmpareA_Enable_ISR();
		Enable_Global_ISR();
	}
	#endif
	
}
/**  Clear Registers of Timer 0**/
void Timer0_ClearReg(void)
{
	CLEAR_REG(TCCR0A);
	CLEAR_REG(TCCR0B);
	CLEAR_REG(TCNT0);
	CLEAR_BIT(TIMSK0, TOIE0);
    CLEAR_BIT(TIMSK0, OCIE0A);
	CLEAR_BIT(TIMSK0, OCIE0B);
	CLEAR_BIT(TIFR0, TOV0);
	CLEAR_BIT(TIFR0, OCF0A);
	CLEAR_BIT(TIFR0, OCF0B);
}
/**  Calculate Prescaler and Counter value of Timer 0**/
void ConfigReg(void)
{

	uint32 NX = 0;
	NX = F_CLK / (2*INIT_TIME);
	if(NX % clk_8 == 0 && (NX/clk_8) < 256)
	{
		prescaler = clk_8;
		count = (NX / clk_8)-1;
	}else if(NX % clk_64 == 0 && (NX/clk_64) <256)
	{
		prescaler = clk_64;
		count = (NX / clk_64)-1;
	}else if(NX % clk_256 == 0 && (NX/clk_256) <256)
	{
		prescaler = clk_256;
		count = (NX / clk_256)-1;
	}else if(NX % clk_1024 == 0 && (NX/clk_1024) <256)
	{
		prescaler = clk_1024;
		count = (NX / clk_1024)-1;
	}
}
/**  Select the mode and type of output
 * First Argument is about timer mode NORMAL ,PHASE_CORRECT_PWM,CTC,FAST_PWM
 * Second Argument is about timer output NORMAL_PORT,TOGGLE_OC0,CLEAR_OC0,SET_OC0
 * All the data can be found in TIMER0.h
 * **/
void TIMER0_Configure_Mode(TMR0_Mode mode, OUT_mode out)
{
	switch(mode)
	{
		case NORMAL:
		    CLEAR_BIT(TCCR0A, WGM00);
			CLEAR_BIT(TCCR0A, WGM01);
			CLEAR_BIT(TCCR0B, WGM02);
			switch(out)
			{
				case NORMAL_PORT:
				    CLEAR_BIT(TCCR0A, COM0A0);
				    CLEAR_BIT(TCCR0A, COM0A1);
				    CLEAR_BIT(TCCR0B, COM0A0);
				    CLEAR_BIT(TCCR0B, COM0A1);
				break;
				
				case TOGGLE_OC0:
				    SET_BIT(TCCR0A, COM0A0);
				    CLEAR_BIT(TCCR0A, COM0A1);
				    SET_BIT(TCCR0B, COM0A0);
				    CLEAR_BIT(TCCR0B, COM0A1);
				break;
				
				case CLEAR_OC0:
				    CLEAR_BIT(TCCR0A, COM0A0);
				    SET_BIT(TCCR0A, COM0A1);
				    CLEAR_BIT(TCCR0B, COM0A0);
				    SET_BIT(TCCR0B, COM0A1);
				break;
				
				case SET_OC0:
				    SET_BIT(TCCR0A, COM0A0);
				    SET_BIT(TCCR0A, COM0A1);
				    SET_BIT(TCCR0B, COM0A0);
				    SET_BIT(TCCR0B, COM0A1);
				break;
				
				default:
				break;
			}
		break;
		
		case PHASE_CORRECT_PWM:
		    SET_BIT(TCCR0A, WGM00);
		    CLEAR_BIT(TCCR0A, WGM01);
		    CLEAR_BIT(TCCR0B, WGM02);
			switch(out)
			{
				case NORMAL_PORT:
				CLEAR_BIT(TCCR0A, COM0A0);
				CLEAR_BIT(TCCR0A, COM0A1);
				CLEAR_BIT(TCCR0B, COM0A0);
				CLEAR_BIT(TCCR0B, COM0A1);
				break;				
				
				case CLEAR_OC0:
				CLEAR_BIT(TCCR0A, COM0A0);
				SET_BIT(TCCR0A, COM0A1);
				CLEAR_BIT(TCCR0B, COM0A0);
				SET_BIT(TCCR0B, COM0A1);
				break;
				
				case SET_OC0:
				SET_BIT(TCCR0A, COM0A0);
				SET_BIT(TCCR0A, COM0A1);
				SET_BIT(TCCR0B, COM0A0);
				SET_BIT(TCCR0B, COM0A1);
				break;
				
				default:
				break;
			}
			
		break;
		
		case CTC:
		    CLEAR_BIT(TCCR0A, WGM00);
		    SET_BIT(TCCR0A, WGM01);
		    CLEAR_BIT(TCCR0B, WGM02);
			switch(out)
			{
				case NORMAL_PORT:
				CLEAR_BIT(TCCR0A, COM0A0);
				CLEAR_BIT(TCCR0A, COM0A1);
				CLEAR_BIT(TCCR0B, COM0A0);
				CLEAR_BIT(TCCR0B, COM0A1);
				break;
				
				case TOGGLE_OC0:
				SET_BIT(TCCR0A, COM0A0);
				CLEAR_BIT(TCCR0A, COM0A1);
				SET_BIT(TCCR0B, COM0A0);
				CLEAR_BIT(TCCR0B, COM0A1);
				break;
				
				case CLEAR_OC0:
				CLEAR_BIT(TCCR0A, COM0A0);
				SET_BIT(TCCR0A, COM0A1);
				CLEAR_BIT(TCCR0B, COM0A0);
				SET_BIT(TCCR0B, COM0A1);
				break;
				
				case SET_OC0:
				SET_BIT(TCCR0A, COM0A0);
				SET_BIT(TCCR0A, COM0A1);
				SET_BIT(TCCR0B, COM0A0);
				SET_BIT(TCCR0B, COM0A1);
				break;
				
				default:
				break;
			}
		break;
		
		case FAST_PWM:
		    SET_BIT(TCCR0A, WGM00);
		    SET_BIT(TCCR0A, WGM01);
		    CLEAR_BIT(TCCR0B, WGM02);
			switch(out)
			{
				case NORMAL_PORT:
				CLEAR_BIT(TCCR0A, COM0A0);
				CLEAR_BIT(TCCR0A, COM0A1);
				CLEAR_BIT(TCCR0B, COM0A0);
				CLEAR_BIT(TCCR0B, COM0A1);
				break;
				
				case CLEAR_OC0:
				CLEAR_BIT(TCCR0A, COM0A0);
				SET_BIT(TCCR0A, COM0A1);
				CLEAR_BIT(TCCR0B, COM0A0);
				SET_BIT(TCCR0B, COM0A1);
				break;
				
				case SET_OC0:
				SET_BIT(TCCR0A, COM0A0);
				SET_BIT(TCCR0A, COM0A1);
				SET_BIT(TCCR0B, COM0A0);
				SET_BIT(TCCR0B, COM0A1);
				break;
				
				default:
				break;
			}
		break;
		
		default:
		break;
	}
}
/**  Select the clock source
 * clk_1, clk_8, clk_64, clk_256, clk_1024, EXTclk_Falling_Edge, EXTclk_Rising_Edge
 * All the data can be found in TIMER0.h
 * **/
void TIMER0_Configure_CLK(CLK_Mode clk_mode)
{
    switch(clk_mode)
	{
		case No_clk:
		    CLEAR_BIT(TCCR0B, CS00);
			CLEAR_BIT(TCCR0B, CS01);
			CLEAR_BIT(TCCR0B, CS02);
		break;
		
		case clk_1:
		    SET_BIT(TCCR0B, CS00);
		    CLEAR_BIT(TCCR0B, CS01);
		    CLEAR_BIT(TCCR0B, CS02);
		break;
		
		case clk_8:
		    CLEAR_BIT(TCCR0B, CS00);
		    SET_BIT(TCCR0B, CS01);
		    CLEAR_BIT(TCCR0B, CS02);
		break;
		
		case clk_64:
		    SET_BIT(TCCR0B, CS00);
		    SET_BIT(TCCR0B, CS01);
		    CLEAR_BIT(TCCR0B, CS02);
		break;
		
		case clk_256:
		    CLEAR_BIT(TCCR0B, CS00);
		    CLEAR_BIT(TCCR0B, CS01);
		    SET_BIT(TCCR0B, CS02);
		break;
		
		case clk_1024:
		    SET_BIT(TCCR0B, CS00);
		    CLEAR_BIT(TCCR0B, CS01);
		    SET_BIT(TCCR0B, CS02);
		break;
		
		case EXTclk_Falling_Edge:
		    CLEAR_BIT(TCCR0B, CS00);
		    SET_BIT(TCCR0B, CS01);
		    SET_BIT(TCCR0B, CS02);
		break;
		
		case EXTclk_Rising_Edge:
		    SET_BIT(TCCR0B, CS00);
		    SET_BIT(TCCR0B, CS01);
		    SET_BIT(TCCR0B, CS02);
		break;
		
		default:
		break;
	}	
}
/*To load TCNT0 value*/
void TIMER0_set_timer_value(uint8 value)
{
	ASSIGN_REG(TCNT0, value);
}
/*To load OCR0A value*/
void TIMER0_set_out_compareA_value(uint8 value)
{
	TIMER0_clear_outcompareA_flag();
	TIMER0_clear_overflow_flag();
	TIMER0_set_timer_value(0x00);
	ASSIGN_REG(OCR0A, value);
}
/*To load OCR0B value*/
void TIMER0_set_out_compareB_value(uint8 value)
{
	TIMER0_clear_outcompareB_flag();
	TIMER0_clear_overflow_flag();
	TIMER0_set_timer_value(0x00);
	ASSIGN_REG(OCR0B, value);
}
/*Enable Interrupt for timer overflow*/
void TIMER0_Overflow_Enable_ISR(void)
{
	SET_BIT(TIMSK0, TOIE0);
}
/*Disable Interrupt for timer overflow*/
void TIMER0_Overflow_Disable_ISR(void)
{
	CLEAR_BIT(TIMSK0, TOIE0);
}
/*Enable Interrupt for PWM*/
void TIMER0_OutcmpareA_Enable_ISR(void)
{
	SET_BIT(TIMSK0, OCIE0A);
}
/*Disable Interrupt for PWM*/
void TIMER0_OutcmpareA_Disable_ISR(void)
{
	CLEAR_BIT(TIMSK0, OCIE0A);
}
/*Enable Interrupt for PWM*/
void TIMER0_OutcmpareB_Enable_ISR(void)
{
	SET_BIT(TIMSK0, OCIE0B);
}
/*Disable Interrupt for PWM*/
void TIMER0_OutcmpareB_Disable_ISR(void)
{
	CLEAR_BIT(TIMSK0, OCIE0B);
}
/*Get the status of flag overflow*/
uint8 TIMER0_get_overflow_flag(void)
{
   return(GET_BIT(TIFR0, TOV0));	
}
/*Get the status of out compare match status*/
uint8 TIMER0_get_outcompareA_flag(void)
{
	return(GET_BIT(TIFR0, OCF0A));
}
/*Get the status of out compare match status*/
uint8 TIMER0_get_outcompareB_flag(void)
{
	return(GET_BIT(TIFR0, OCF0B));
}
/*Clear the status of flag overflow*/
void TIMER0_clear_overflow_flag(void)
{
	CLEAR_BIT(TIFR0, TOV0);
}
/*Get the status of out compare match status*/
void TIMER0_clear_outcompareA_flag(void)
{
	CLEAR_BIT(TIFR0, OCF0A);
}
/*Get the status of out compare match status*/
void TIMER0_clear_outcompareB_flag(void)
{
	CLEAR_BIT(TIFR0, OCF0B);
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