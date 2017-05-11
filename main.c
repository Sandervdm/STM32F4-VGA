//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: J.F. van der Bent
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

#include "main.h"

void UART_init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);   // USART2_TX
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);  // USART2_RX

	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART2, &USART_InitStructure);
	USART_Cmd(USART2, ENABLE);
}

void UART_putchar(char c)
{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET); // Wait for Empty
	USART_SendData(USART2, c);
}

char UART_get(void)
{
    char uart_char = -1;
    if (USART_GetFlagStatus(USART2, USART_FLAG_RXNE)== SET)
    {
    	 uart_char= USART2->DR & 0xFF; // and read the data from peripheral
    }
    return uart_char;
}

void UART_puts(char *s)
{
	while(*s != 0) {
		UART_putchar(*s);
		s++;
	}
	UART_putchar(10);
}



int main(void)
{
	///////////////////////////////////////////////////////////
	// Initialize system
	SystemInit();
	UART_init();

	// Initialize screen
	UB_VGA_Screen_Init();
	UB_VGA_FillScreen(VGA_COL_WHITE);

	//font_write_string("TestString 0123456789", FONT_ONE, STYLE_FLASH, 0, 0, 16, VGA_COL_RED);
	//font_write_string("TestString 0123456789", FONT_TWO, STYLE_NONE, 0, 16, 16, VGA_COL_RED);
	//font_write_string("TestString 0123456789", FONT_THREE, STYLE_NONE, 0, 32, 16, VGA_COL_RED);

	draw_bmp(BMP_ARROW_LEFT, 10, 10);
	draw_bmp(BMP_ARROW_RIGHT, 70, 10);
	draw_bmp(BMP_ARROW_UP, 130, 10);
	draw_bmp(BMP_ARROW_DOWN, 190, 10);

	draw_bmp(BMP_SMILEY_MAD, 10, 60);
	draw_bmp(BMP_SMILEY_HAPPY, 100, 60);

	draw_line(50,200,150,210,0,0,0);
	draw_line(50,190,150,190,0,0,0);
	//TODO: shit werkt nog niet
	draw_line(150,100,150,190,0,0,0);

	char buffer[50];
	int buffercounter = 10;

    while(1)
    {
    	if(SecTick()) {
    		font_blink_poll();
    	}
    	//while(GPIOB->BSRRL & GPIO_Pin_11);
    	if(USART2->SR & USART_FLAG_RXNE)
    	{
    	 	char temp = USART2->DR & 0xFF;
    		if(temp == 10)
    		{
    			buffer[buffercounter] = 0;
    			font_write_string(buffer, FONT_TWO, STYLE_NONE, 0, 0, 16, VGA_COL_BLACK);
    			buffercounter = 0;
    		}
    		else if(temp >= 32 && temp <= 128)
    		{
    			buffer[buffercounter] = temp;
    			buffercounter++;
    		}
    	}
    	int x;
    	for(x=0;x<15000;x++);
    }
}

