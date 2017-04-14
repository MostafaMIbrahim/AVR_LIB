/*
 * SPI.c
 *
 * Created: 3/19/2017 1:32:21 PM
 *  Author: moibrahim
 */ 
#include <avr/interrupt.h>
#include "Types.h"
#include "Util.h"
#include "memmaps.h"
#include "DIO.h"
#include "SPI.h"


static void SPI_Enable(void);
static void SPI_Disable(void);
static void SPI_Enable_ISR(void);
static void SPI_Disable_ISR(void);
static void SPI_Configure_Mode (uint8 Mode);
static void SPI_Configure_Prescalar(SPI_Prescalar Prescalar);

/*SPI Init*/
void SPI_init(void)
{
    CLEAR_REG(SPCR);
    CLEAR_BIT(SPCR,SPIF);
    CLEAR_BIT(SPCR,WCOL);
    CLEAR_BIT(SPCR,SPI2X);
	
	SPI_Configure_Prescalar(SPI_CLK);
	SPI_Configure_Mode(SPI_MODE_OPT);
	SPI_Enable();
		
}

/*Enable SPI*/
void SPI_Enable(void)
{
	SET_BIT(SPCR ,SPE);
}
/*Disable SPI*/
void SPI_Disable(void)
{
	CLEAR_BIT(SPCR ,SPE);
}
/*Enable SPI ISR*/
void SPI_Enable_ISR(void)
{
	SET_BIT(SPCR , SPIE);
}

/*Disable Disable ISR*/
void SPI_Disable_ISR(void)
{
	CLEAR_BIT(SPCR , SPIE);
}
/*Select mode of operation*/
void SPI_Configure_Mode (uint8 Mode)
{
	if (Mode==SPI_Master_Mode_Enable)
	SET_BIT(SPCR,MSTR);
	else
	CLEAR_BIT(SPCR,MSTR);
}
/*Select the presca;a 2,4,8,16,32,64,128*/
void SPI_Configure_Prescalar (SPI_Prescalar Prescalar)
{
	switch (Prescalar)
	{
		case N2:
		CLEAR_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;

		case N4:
		CLEAR_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break;

		case N8:
		SET_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;

		case N16:
		SET_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break;

		case N32:
		CLEAR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;

		case N64:
		CLEAR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break;

		case N128:
		SET_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break;

		default:
		break;
	}
}
/*Send byte*/
void SPI_send_byte(uint8 data)
{
	// SS = portB0
	Dio_WriteOnPin(portB0,LOW);
	SPDR=data;
	while((GET_BIT(SPSR,SPIF))==0);
	Dio_WriteOnPin(portB0,HIGH);
}

/*Send a string/Bytes*/
void SPI_send_string (uint8 *string)
{
	unsigned char i=0;
	while (string[i] !=0)
	{
		SPI_send_byte(string[i]);
		i++;
	}
}

/*Receive byte*/
uint8 SPI_Receive (void)
{
	while((GET_BIT(SPSR,SPIF))==0);
	return SPDR;
}
