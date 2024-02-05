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

static int	key_input(int key, t_control *control)
{
	if (key == 6 && !control->trans->z_rot_bool)
		control->trans->z_rot += 0.05;
	if (key == 8 && !control->trans->z_rot_bool)
		control->trans->y_rot += 0.05;
	if (key == 7 && !control->trans->z_rot_bool)
		control->trans->x_rot += 0.05;
	if (key == 3)
		control->trans->z_scale += 1;
	if (key == 9)
		control->trans->z_scale -= 1;
	if (key == 15)
		control_reset(control);
	if (key == 38)
	{
		if (!control->trans->z_rot_bool)
			control->trans->z_rot_bool = 1;
		else
			control->trans->z_rot_bool = 0;
	}
	if (key == 40)
	{
		if (!control->trans->x_rot_bool)
			control->trans->x_rot_bool = 1;
		else
			control->trans->x_rot_bool = 0;
	}
	if (key == 37)
	{
		if (!control->trans->y_rot_bool)
		control->trans->y_rot_bool = 1;
	else
		control->trans->y_rot_bool = 0;
	}
	if (key == 35)
	{
		control_reset(control);
		if (control->trans->projection == 0)
			control->trans->projection = 1;
		else
			control->trans->projection = 0;
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