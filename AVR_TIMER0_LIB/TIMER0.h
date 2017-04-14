/*
 * TIMER0.h
 *
 * Created: 2/20/2017 2:47:02 AM
 *  Author: moibrahim
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

  #include "TIMER0_cfg.h"
  typedef enum
  {
	  NORMAL_PORT = 0,
	  TOGGLE_OC0,
	  CLEAR_OC0,
	  SET_OC0
  }OUT_mode;
  
  typedef enum
  {
	 NORMAL = 0,
	 PHASE_CORRECT_PWM,
	 CTC,
	 FAST_PWM
  }TMR0_Mode;
  
  typedef enum
  {   
	  No_clk = 0,
	  clk_1 = 1,
	  clk_8 = 8,
	  clk_64 = 64,
	  clk_256 = 256,
	  clk_1024 = 1024,
	  EXTclk_Falling_Edge = 2,
	  EXTclk_Rising_Edge = 3
  }CLK_Mode;
  
  extern void Timer0_InitAndRun(void);
  
#endif /* TIMER0_H_ */