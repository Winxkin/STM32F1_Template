#ifndef __DHT_H
#define __DHT_H	
#include "delay.h"
#include "stm32f10x_gpio.h"
#include "stdint.h"
#include "stdio.h"	

uint8_t Read_temp_humi(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x, uint8_t* temp, uint8_t* humi);
uint8_t Read_temp(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x);
uint8_t Read_humi(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x);

#endif

