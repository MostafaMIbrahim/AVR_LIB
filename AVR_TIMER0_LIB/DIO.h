/*
 * DIO.h
 *
 * Created: 1/31/2017 7:22:08 PM
 *  Author: moibrahim
 */ 


#ifndef DIO_H_
#define DIO_H_
    
	#include "DIO_Private.h"
    #include "DIO_cfg.h"
	typedef enum
	{
		PA,
		PB,
		PC,
		PD,
		PE,
		PF,
		PG,
		PH,
		PJ,
		PK,
		PL
	}port_type;

	
    extern void Dio_InitReg(void);
	extern void Dio_WriteOnPin(Dio_pin_type input,uint8 value);
    extern void Dio_WriteOnPort(port_type port,uint8 value);
	extern uint8 Dio_ReadFromPin(Dio_pin_type input);
	extern uint8 Dio_ReadFromPort(port_type port);

#endif /* DIO_H_ */