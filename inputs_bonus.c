#include "fdf.h"

void control_reset(t_control *control)
{
	control->trans->scale = 0;
	control->trans->z_scale = 1;
	control->trans->x_pos = 0;
	control->trans->y_pos = 0;
	control->trans->x_rot = 0;
	control->trans->y_rot = 0;
	control->trans->z_rot = 0;
}

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

void	inputs(t_control *control)
{
	mlx_hook(control->mlx->mlx_win, 4, 0, mouse_press, control);
	mlx_hook(control->mlx->mlx_win, 6, 0, mouse_hold, control);
	mlx_hook(control->mlx->mlx_win, 5, 0, mouse_release, control);
	mlx_hook(control->mlx->mlx_win, 3, 0, key_input, control);
	mlx_hook(control->mlx->mlx_win, 2, 0, key_close_window, control);
	mlx_hook(control->mlx->mlx_win, 17, 0, close_window, control);
}