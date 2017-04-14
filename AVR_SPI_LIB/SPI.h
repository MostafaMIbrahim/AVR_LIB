/*
 * SPI.h
 *
 * Created: 3/19/2017 1:32:32 PM
 *  Author: moibrahim
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "SPI_cfg.h"
  
#if SPI_Master_Mode_Enable==1
#define SPI_MODE_OPT	SPI_Master_Mode_Enable
#endif

#if SPI_Slave_mode_Enable==1
#define SPI_MODE_OPT	SPI_Slave_mode_Enable
#endif

#define		LOW					0
#define		HIGH				1

typedef enum
{
	N2 = 0,
	N4,
	N8,
	N16,
	N32,
	N64,
	N128
}SPI_Prescalar;
extern void SPI_init(void);
extern void SPI_send_byte(uint8 data);
extern void SPI_send_string (uint8 *string);
extern uint8 SPI_Receive(void);

#endif /* SPI_H_ */