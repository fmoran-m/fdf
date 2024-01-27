#include "fdf.h"

static int	close_window(t_control *control)
{
	mlx_destroy_window(control->mlx->mlx, control->mlx->mlx_win);
	exit(0);
}

static int key_close_window(int key, t_control *control)
{
	if(key == 53)
	{
		mlx_destroy_window(control->mlx->mlx, control->mlx->mlx_win);
		exit(0);
	}
	return (0);
}
static	int	key_input(int key, t_control *control)
{
	if (key == 'e')
		control->trans->scale += 1;
	if (key == 'q')
		control->trans->scale -= 1;
	if (key == 'w')
		control->trans->y_pos -= 15;
	if (key == 's')
		control->trans->y_pos += 15;
	if (key == 'd')
		control->trans->x_pos += 15;
	if (key == 'a')
		control->trans->x_pos -= 15;
	if (key == 'z')
		control->trans->z_rot += 0.05;
	if (key == 'c')
		control->trans->y_rot += 0.05;
	if (key == 'x')
		control->trans->x_rot += 0.05;
	if (key == 'f')
		control->trans->z_scale += 1;
	draw_map(control->matrix, control->map, control->mlx, control->trans);
	return (0);
}

void	inputs(t_control *control)
{
	mlx_key_hook(control->mlx->mlx_win, key_input, control);
	mlx_hook(control->mlx->mlx_win, 2, 1L<<0, key_close_window, control);
	mlx_hook(control->mlx->mlx_win, 17, 0, close_window, control);
}