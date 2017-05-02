#include "main.h"

#define FONT_ONE 		1
#define FONT_TWO		2

#define STYLE_NONE		0
#define STYLE_BOLD		1
#define STYLE_FLASH		2

extern void font_write_string(char* str, unsigned char font_type, unsigned char style_type, unsigned char size, unsigned char color);
