#include "fdf.h"

void	bressen(t_data img, int x0, int x1, int y0, int y1)
{
	int	dx = x1 - x0;
	int dy = y1 - y0;
	int	sx = 0;
	int	sy = 0;
	int avr;
	int	av;
	int	avi;
	int	temp;

	temp = 0;
	if (dx < 0)
	{
		sx = -1;
		dx = -dx; 
	}
	else if (dx > 0)
		sx = 1;
	if (dy < 0)
	{
		sy = -1;
		dy = -dy;	
	}
	else if (dy > 0)
		sy = 1;
	if (dy > dx)
	{
		dy = temp;
		dy = dx;
		dx = temp;
	}
	avr = (2 * dy);
	av = (avr - dx);
	avi = (av - dx);
	while (x0 < x1 && y0 < y1)
	{
		put_img_pixel(img, x0, y0, MAIN_COLOR);
		if (av >= 0)
		{
			y0 += sy;
			x0 += sx;
			av += avi;
		}
		else
		{
			x0 += sx;
			av += avr;
		}
	}
}
