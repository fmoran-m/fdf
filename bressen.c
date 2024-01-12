#include "fdf.h"

static double	get_color_step(int color1, int color2, int dx, int dy)
{
	int total;
	int	color_step;

	total = dx;
	if (!color1)
		color1 = color2;
	if (!color2)
		color2 = color1;
	if (color1 == color2)
		return (0);
	if (dy > dx)
		total = dy;
	if (total != 0)
		color_step = (color2 - color1) / total;
	else
		color_step = 0;
	printf("%d\n", total);
	return (color_step);
}

void	bressen(t_data img, int x0, int x1, int y0, int y1, int color1, int color2)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy;
	double color_step;
	double color;

	color_step = get_color_step(color1, color2, dx, dy);
	color = color1;
    if (x0 < x1) 
        sx = 1;
    else 
        sx = -1;
    if (y0 < y1) 
        sy = 1;
     else 
        sy = -1;
    int err = dx - dy;
    while (x0 != x1 || y0 != y1)
	{
		put_img_pixel(img, x0, y0, color);
		color += color_step;
        int err2 = 2 * err;

        if (err2 > -dy)
		{
			err -= dy;
			x0 += sx;
        }
        if (err2 < dx)
		{
            err += dx;
            y0 += sy;
        }
    }
}
