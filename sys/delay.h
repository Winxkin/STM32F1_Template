#ifndef __DELAY_H
#define __DELAY_H 
#include "stm32f10x_tim.h"
/* delay with system clock = 36Mhz */
#define period_us 36
#define period_ms 36000
#define Prescaler 1

void delay_us (uint32_t us);
void delay_ms (uint32_t ms);
void Timer_init (void);

#endif
