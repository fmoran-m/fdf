#include "fdf.h"

int	get_light(int start, int end, double percentage)
{
	return ((int)((1.0f - percentage) * start + percentage * end));
}

int	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int	get_color(t_node node1, t_node node2, int x, int y, int dx, int dy, int color)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (color == node2.color)
		return (node2.color);
	if (dx > dy)
		percentage = percent(node1.x, node2.x, x);
	else
		percentage = percent(node1.y, node2.y, y);
	red = get_light((node1.color >> 16) & 0xFF,
					(node2.color >> 16) & 0xFF,
					percentage);
	green = get_light((node1.color >> 8) & 0xFF,
					(node2.color >> 8) & 0xFF,
					percentage);
	blue = get_light(node1.color & 0xFF,
					node2.color & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}


void bressen(t_node node1, t_node node2, t_mlx *mlx)
{
    int dx = abs(node2.x - node1.x);
    int dy = abs(node2.y - node1.y);
	int err_x, err_y;
    int sx, sy;
	int	x;
	int y;
	int	color = node1.color;

    if (node1.x < node2.x) 
        sx = 1;
    else 
        sx = -1;
    if (node1.y < node2.y) 
        sy = 1;
    else 
	{
        sy = -1;
	}
	err_x = 0;
	err_y = 0;
	x = node1.x;
	y = node1.y;
	while (x != node2.x || y != node2.y)
	{
		color = get_color(node1, node2, x, y, dx, dy, color);
		put_img_pixel(mlx, x, y, color);
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