#include "fdf.h"

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int	get_color(int x0, int y0, int x1, int y1, int x, int y, int dx, int dy, int color1, int color2, int color)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (color == color2)
		return (color2);
	if (dx > dy)
		percentage = percent(x0, x1, x);
	else
		percentage = percent(y0, y1, y);
	red = get_light((color1 >> 16) & 0xFF,
					(color2 >> 16) & 0xFF,
					percentage);
	green = get_light((color1 >> 8) & 0xFF,
					(color2 >> 8) & 0xFF,
					percentage);
	blue = get_light(color1 & 0xFF,
					color2 & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}


void bressen(t_data img, int x0, int x1, int y0, int y1, int color1, int color2)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
	int err_x, err_y;
    int sx, sy;
	int	x;
	int y;
	int	color = color1;

    if (x0 < x1) 
        sx = 1;
    else 
        sx = -1;
    if (y0 < y1) 
        sy = 1;
    else 
	{
        sy = -1;
	}
	err_x = 0;
	err_y = 0;
	x = x0;
	y = y0;
	while (x != x1 || y != y1)
	{
		color = get_color(x0, y0, x1, y1, x, y, dx, dy, color1, color2, color);
		put_img_pixel(img, x, y, color);
		err_x += dx;
		if (err_x >= dy)
		{
			err_x -= dy;
			x += sx;
		}
		err_y += dy;
		if (err_y >= dx)
		{
			err_y -= dx;
			y += sy;
		}
	}
}