/*
 * memmaps.h
 *
 * Created: 3/19/2017 1:31:35 PM
 *  Author: moibrahim
 */ 


#ifndef MEMMAPS_H_
#define MEMMAPS_H_


/****************SPI*******************/

#define		SPCR					(*(volatile uint8 *)0x4C)
#define		SPSR					(*(volatile uint8 *)0x4D)
#define		SPDR					(*(volatile uint8 *)0x4E)

/* SPCR */
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0

/* SPSR */
#define SPIF    7
#define WCOL    6
/* bits 5-1 reserved */
#define SPI2X   0

/* SPCR */
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0



#endif /* MEMMAPS_H_ */