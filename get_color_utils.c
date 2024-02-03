#include "fdf.h"

int	get_red(int color)
{
	int red;

	red = (color >> 16) & 0xFF;
	return (red);
}

int	get_green(int color)
{
	int green;

	green = (color >> 8) & 0xFF;
	return (green);
}

int	get_blue(int color)
{
	int blue;

	blue = color & 0xFF;
	return (blue);
}