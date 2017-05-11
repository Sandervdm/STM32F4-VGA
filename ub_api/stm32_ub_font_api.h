#include "main.h"

//define the height and width of the font
#define FONT_CHAR_HEIGHT		16
#define FONT_CHAR_WIDTH			9

//function define
extern void font_blink_poll(void);

extern void font_write_string(char* str, FONT_TYPE font_type, STYLE_TYPE style_type, unsigned int posX, unsigned int posY, unsigned char size, unsigned char color);
