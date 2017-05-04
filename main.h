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
	FONT_TWO
} FONT_TYPE;

typedef enum{
	STYLE_NONE,
	STYLE_BOLD,
	STYLE_FLASH
} STYLE_TYPE;

/*
 * includes from stm32 libraries and API
 */

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_dma.h"
#include "misc.h"
#include <math.h>

#include "stm32_ub_vga_screen.h"
#include "stm32_ub_bitmap_api.h"
#include "stm32_ub_font_api.h"
#include "stm32_ub_pixel_api.h"
#include "stm32_ub_shape_api.h"

#endif // __STM32F4_UB_MAIN_H
