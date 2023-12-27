#include "fdf.h"

void	bressen(t_data img, int x0, int x1, int y0, int y1)
/*
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
	if (dx >= 0)
		sx = 1;
	else
	{
		sx = -1;
		dx = -dx;
	}
	if (dy >= 0)
		sy = 1;
	else
	{
		sy = -1;
		dy = -dy;
	}
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
*/
{
	int	dx = x1 - x0;
	int	dy = y1 - y0;
	int x_flag = 1;
	int	y_flag = 1;
	int	x_error = 0;
	int	y_error = 0;
	int	temp;
	int	av;
	int	avr;
	int	avi;

	if (dx < 0)
	{
		x_flag = -1;
		dx = -dx;
	}
	if (dy < 0)
	{
		y_flag = -1;
		dy = -dy;
	}
	if (dx >= dy)
		x_error = x_flag;
	else
	{
		y_error = y_flag;
		temp = dx;
		dx = dy;
		dy = temp;
	}
	avr = (dy * 2);
	av = (avr - dx);
	avi = (av - dx);
	while (y0 != y1 && x0 != x1)
	{
		put_img_pixel(img, x0, y0, MAIN_COLOR);
		if (av >= 0)
		{
			x0 += x_error;
			y0 += y_error;
			av = av + avi;
		}
		else
		{
			x0 += x_flag;
			y0 += y_flag;
			av = av + avr;
		}
	}
}
