#ifndef __LCD_H
#define __LCD_H	
#include "stm32f10x_gpio.h"
#include "delay.h"
#include "stdint.h"
#include "stm32f10x_rcc.h"
#include "stdio.h"	

#define D0  GPIO_Pin_1
#define D1	GPIO_Pin_2
#define D2	GPIO_Pin_3
#define D3	GPIO_Pin_4
#define D4	GPIO_Pin_5
#define D5	GPIO_Pin_6
#define D6	GPIO_Pin_7
#define D7	GPIO_Pin_8
#define LCD_EN GPIO_Pin_9
#define LCD_RS GPIO_Pin_10

#define clear 		0x01
#define display 	0x0C
#define dis_2line 0x38


#define line1 		0x80
#define line2 		0xC0
#define line3			0x94
#define line4			0xD4
#define p_firstln 0x02

typedef enum
{ l1=1,
	l2=2,
	l3=3,
	l4=4
} _line;


void LCD_displaystr (GPIO_TypeDef* GPIOx, uint8_t *str, _line line);
void LCD_setfull_str (GPIO_TypeDef* GPIOx, uint8_t *str1, uint8_t *str2);
void LCD_displaynum (GPIO_TypeDef* GPIOx, uint8_t _int,_line line);



#endif

