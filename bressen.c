#include "fdf.h"

int	get_light(int start, int end, double percentage)
{
	return (((1.0 - percentage) * start + percentage * end));
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

unsigned int	get_color(t_node node1, t_node node2, t_bressen vars)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (vars.color == node2.color)
		return (node2.color);
	if (vars.dx > vars.dy)
		percentage = percent(node1.x, node2.x, vars.x);
	else
		percentage = percent(node1.y, node2.y, vars.y);
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

static int	get_direction(int num1, int num2) 
{
	int	s;
	
	s = 0;
	if (num1 < num2)
		s = 1;
	else
		s = -1;
	return (s);
}

static void	new_xerror(int *err_x, int *x, int dy, int sx)
{
	if (*err_x >= dy)
	{
		*err_x -= dy;
		*x += sx;
	}
}

static void	new_yerror(int *err_y, int *y, int dx, int sy)
{
	if (*err_y >= dx)
	{
		*err_y -= dx;
		*y += sy;
	}
}

void bressen(t_node node1, t_node node2, t_mlx *mlx)
{
	t_bressen	vars;

	vars = bressen_vars_init(node1, node2);
	vars.sx = get_direction(node1.x, node2.x);
	vars.sy = get_direction(node1.y, node2.y);
	vars.err_x = 0;
	vars.err_y = 0;
	vars.x = node1.x;
	vars.y = node1.y;
	while (vars.x != node2.x || vars.y != node2.y)
	{
		vars.color = get_color(node1, node2, vars);
		put_img_pixel(mlx, vars.x, vars.y, vars.color);
		vars.err_x += vars.dx;
		new_yerror(&vars.err_x, &vars.x, vars.dy, vars.sx);
		vars.err_y += vars.dy;
		new_xerror(&vars.err_y, &vars.y, vars.dx, vars.sy);
	}
}