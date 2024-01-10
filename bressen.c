#include "fdf.h"

static int	get_color_step(int color1, int color2, int dx, int dy)
{
	int	total;
	int	color;
	int	color_step;

	if (dy > dx)
		total = dy;
	else 
		total = dx;
	color = color2 - color1;
	color_step = color / total;
	return (color_step);
}

void	bressen(t_data img, int x0, int x1, int y0, int y1, int color1, int color2)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy;
	int color_step;

	color_step = get_color_step(color1, color2, dx, dy);
    if (x0 < x1) {
        sx = 1;
    } else {
        sx = -1;
    }

    if (y0 < y1) {
        sy = 1;
    } else {
        sy = -1;
    }

    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {

		put_img_pixel(img, x0, y0, color1 + color_step);
        int err2 = 2 * err;

        if (err2 > -dy) {
            err -= dy;
            x0 += sx;
        }

        if (err2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}