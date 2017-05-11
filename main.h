#ifndef __STM32F4_UB_MAIN_H
#define __STM32F4_UB_MAIN_H

/*
 * Enumerate typedefs
 */

typedef enum{
	BMP_ARROW_UP,
	BMP_ARROW_DOWN,
	BMP_ARROW_LEFT,
	BMP_ARROW_RIGHT,
	BMP_SMILEY_MAD,
	BMP_SMILEY_HAPPY
} BMP_Images;

typedef enum{
	FONT_ONE,
	FONT_TWO,
	FONT_THREE
} FONT_TYPE;

typedef enum{
	STYLE_NONE,
	STYLE_BOLD,
	STYLE_FLASH
} STYLE_TYPE;

struct blinkSkeleton{
	FONT_TYPE font_type;
	char str[50];
	unsigned int posX;
	unsigned int posY;
	unsigned char size;
	unsigned char color;
	unsigned char State;
};

/*
 * includes from stm32 libraries and API
 */

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_dma.h"
#include "misc.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "stm32f4xx_usart.h"

#include "stm32_ub_vga_screen.h"
#include "stm32_ub_bitmap_api.h"
#include "stm32_ub_font_api.h"
#include "stm32_ub_pixel_api.h"
#include "stm32_ub_shape_api.h"

#define BACKGROUND_COLOR		VGA_COL_WHITE

#endif // __STM32F4_UB_MAIN_H
