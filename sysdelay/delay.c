#include "delay.h"

void Timer_init (void)
{
  TIM_TimeBaseInitTypeDef Timer_init;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	Timer_init.TIM_CounterMode = TIM_CounterMode_Up;
	Timer_init.TIM_Period = 65535;
	
	/* system clock = 8Mhz -> prescaler -> Timer clock = 4Mhz 
	 Note: Prescaler set prarm = 1 that mean div pararm = 1 + 1 */   
	
	Timer_init.TIM_Prescaler = 1;  //Timer clock = system clock / (1 + 1)
	TIM_TimeBaseInit (TIM2, &Timer_init);
	

}

void delay_1us (void)
{
	Timer_init ();
	TIM_Cmd (TIM2,ENABLE);
	TIM_SetCounter(TIM2, 0);
	/* 1us = 4 period Prescaler clock */
	while (TIM_GetCounter(TIM2) < period_us);	
	TIM_Cmd (TIM2,DISABLE);
}


void delay_us (uint32_t us)
{
	while (us--)
	{
	   delay_1us();
	}

}

void delay_1ms(void)
{
	Timer_init ();
	TIM_Cmd (TIM2,ENABLE);
	TIM_SetCounter(TIM2, 0);
	/* 1ms = 4000 period Prescaler clock */
	while (TIM_GetCounter(TIM2) < period_ms);	
	TIM_Cmd (TIM2,DISABLE);

}

void delay_ms(uint32_t ms)
{
	while (ms--)
	{
	   delay_1ms();
	}
}

