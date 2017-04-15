/*
 * Schedular.c
 *
 * Created: 11/29/2016 5:59:49 AM
 *  Author: moibrahim
 */ 

#include <avr/interrupt.h>
#include "Types.h"
#include "Timer_Register.h"
#include "Schedular.h"
#include "Button.h"
#include "Dio.h"


static uint16 flag = 0;
static uint16 count = 0;
static boolean isSorted = 0;

//static uint16 seconds = 0;
//static uint8 key = 0;

void f1(void);
void f2(void);
void f3(void);

typedef struct 
{
	uint16 peridocity;
	void (*pf) (void);
	uint8 priority;
}os_cfg_type;

os_cfg_type os_cfg[] = 
{
	  {5, f1, 1},
	//{100, f2, 2},
    //{5000, f3, 3}
};

void Priority(void)
{
  uint8 i;
  for(i =0;i<(sizeof(os_cfg)/sizeof(os_cfg_type));i++)
  {
	  if(os_cfg[i].priority > os_cfg[i+1].priority)
	  {
		  os_cfg_type a;
		  a = os_cfg[i];
		  os_cfg[i] = os_cfg[i+1];
		  os_cfg[i+1] = a;
	  }
  }
  isSorted = 1;
	
}

void startOS(void)
{
	if(!isSorted)
	{
		Priority();
	}	
   if(flag != 0)
   {
	   uint8 i;
	   for ( i = 0; i<(sizeof(os_cfg)/sizeof(os_cfg_type));i++)
	   {
		   if((count % os_cfg[i].peridocity) == 0)
		   {
			   os_cfg[i].pf();
		   }
	   }
	   flag = 0;
   }

}


void f1(void)
{
  Key_Task();
}

void f2(void)
{
   
}

void f3(void)
{	
	
}



ISR(TIMER0_COMPA_vect)
{
	count++;
	
		flag = 1;
	

}