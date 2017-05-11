#include "stm32_ub_shape_api.h"

void draw_line(int posX, int posY, int posXX, int posYY, int thiccness, int fill, unsigned char color)
{
	int offsetX = posXX;
	if(posX <= posXX) {
		offsetX = posX;
	}
	posX -= offsetX;
	posXX -= offsetX;

	int offsetY = posYY;
	if(posY <= posYY) {
		offsetY = posY;
	}
	posY -= offsetY;
	posYY -= offsetY;

	int lengthX = posX - posXX;
	if(lengthX <= 0) {
		lengthX = posXX - posX;
	}

	int lengthY = posY - posYY;
	if(lengthY <= 0) {
		lengthY = posYY - posY;
	}

	if(lengthX > lengthY) {
		float gradient = (float)lengthY / (float)lengthX;
		int i;
		for(i=0;i<lengthX;i++) {
			int corY = gradient * i;
			UB_VGA_SetPixel(offsetX + i, offsetY + corY, color);
		}
	}
	else {
		float gradient = (float)lengthX / (float)lengthY;
		int i;
		for(i=0;i<lengthY;i++) {
			int corX = gradient * i;
			UB_VGA_SetPixel(offsetX + i, offsetY + corX, color);
		}
	}
}

void draw_rectangle(int posX, int posY, int thiccness, int fill, unsigned char color)
{

}

void draw_triangle(int posX, int posY, int thiccness, int fill, unsigned char color)
{

}

void draw_ellips(int posX, int posY, int thiccness, int fill, unsigned char color)
{

}
