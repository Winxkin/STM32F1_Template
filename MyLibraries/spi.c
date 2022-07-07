#include "spi.h"


void SPI2_init (uint16_t BaudRatePrescaler,uint16_t CPHA,uint16_t CPOL,uint16_t DataSize,
								uint16_t Direction,uint16_t FirstBit,uint16_t Mode,uint16_t NSS)
{   
	  
 		GPIO_InitTypeDef  GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	  
	  /*PB12 CS mode _OUT_PP*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;			    
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP ;	 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	  /*PB13 SCK mode _AF_PP*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;			    
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AF_PP ;	 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		/*PB14 MISO mode _IN_FLOATING*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;			    
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN_FLOATING ;	 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	  /*PB15 MOSI mode _AF_PP*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;			    
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AF_PP ;	 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOA, &GPIO_InitStructure);
		
		/*SPI2 clock init max 36Mhz*/
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
		
		
		SPI_InitTypeDef SPI2_init;
		SPI2_init.SPI_BaudRatePrescaler = BaudRatePrescaler;
		SPI2_init.SPI_CPHA = CPHA;
		SPI2_init.SPI_CPOL = CPOL;
		SPI2_init.SPI_DataSize = DataSize;
		SPI2_init.SPI_Direction = Direction;
		SPI2_init.SPI_FirstBit = FirstBit;
		SPI2_init.SPI_Mode = Mode;
		SPI2_init.SPI_NSS = NSS;
		SPI_Init (SPI2, &SPI2_init);
		SPI_Cmd (SPI2, ENABLE);
		
}


void SPI2_Sentdatas (uint16_t CS, uint16_t Data)
{
	GPIO_SetBits(GPIOB, CS);
	
	SPI_I2S_SendData (SPI2,Data );
  while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY)==SET);
	
	GPIO_ResetBits (GPIOB,CS);
  /*CS low active*/
}

void SPI2_Sentsuperdata (uint16_t CS, uint8_t *Pu8data, uint32_t length)
{ 
	GPIO_SetBits(GPIOB, CS);
	while(length--)
	{		
	
	SPI_I2S_SendData (SPI2,*(Pu8data++) );
  while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY)==SET);
	
	}
  GPIO_ResetBits (GPIOB,CS);

}

/*
DMA transfer
SPI2 TX though channel 5
*/

//void SPI2_DMA5_init ()
//{
//  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE );
//	
//	DMA_InitTypeDef DMA_InitStruct;
//	DMA_InitStruct.DMA_BufferSize = BufferSize;
//	DMA_InitStruct.DMA_DIR = DIR;
//	DMA_InitStruct.DMA_M2M = M2M;
//	DMA_InitStruct.DMA_MemoryBaseAddr = MemoryBaseAddr;
//	DMA_InitStruct.DMA_MemoryDataSize = MemoryDataSize;
//	
//	
//	
//	
//	
////	DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct);
//}

