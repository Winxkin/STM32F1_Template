#ifndef __SEG_H
#define __SEG_H	

#include "stm32f10x_gpio.h"
#include "stdint.h"
#include "stm32f10x_rcc.h"
#include "stdio.h"	
//note GPIO_Pin_...
#define a  GPIO_Pin_1
#define b  GPIO_Pin_2
#define c  GPIO_Pin_3
#define d  GPIO_Pin_4
#define e  GPIO_Pin_5
#define f  GPIO_Pin_6
#define g  GPIO_Pin_7
#define dp GPIO_Pin_8


void seg_setnumberA (GPIO_TypeDef* GPIOx, uint8_t number);
void seg_set (GPIO_TypeDef* GPIOx, uint8_t Data);
void seg_setnumberK (GPIO_TypeDef* GPIOx, uint8_t number);

#endif


