#include "fdf.h"

void	bressen(t_data img, int x0, int x1, int y0, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy;

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

		put_img_pixel(img, x0, y0, MAIN_COLOR);
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
