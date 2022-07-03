#ifndef __SPI_H
#define __SPI_H
#include "stm32f10x_gpio.h"
#include "stm32f10x_spi.h"
/* Note pin SPI2
PB12	CS
PB13	SCK
PB14	MISO
PB15	MOSI
*/

void SPI2_init (uint16_t BaudRatePrescaler,uint16_t CPHA,uint16_t CPOL,uint16_t DataSize,
								uint16_t Direction,uint16_t FirstBit,uint16_t Mode,uint16_t NSS);

void SPI2_Sentdatas (uint16_t CS, uint16_t Data);
void SPI2_Sentsuperdata (uint16_t CS, uint8_t *Pu8data, uint32_t length);



#endif
