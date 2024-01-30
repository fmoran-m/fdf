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
	//	printf("Rotation in x is %f\n.", control->trans->x_rot);
		//printf("Rotation in y is %f\n.", control->trans->y_rot);
		//printf("Rotation in z is %f\n.", control->trans->z_rot);
		exit(0);
	}
	return (0);
}
static	int	key_input(int key, t_control *control)
{
	if (key == 14)
		control->trans->scale += 1;
	if (key == 12)
		control->trans->scale -= 1;
	if (key == 13)
		control->trans->y_pos -= 15;
	if (key == 1)
		control->trans->y_pos += 15;
	if (key == 2)
		control->trans->x_pos += 15;
	if (key == 0)
		control->trans->x_pos -= 15;
	if (key == 6)
		control->trans->z_rot += 0.05;
	if (key == 8)
		control->trans->y_rot += 0.05;
	if (key == 7)
		control->trans->x_rot += 0.05;
	if (key == 3)
		control->trans->z_scale += 1;
	if (key == 15)
		control_reset(control);
	if (key == 35)
	{
		control_reset(control);
		if (control->trans->projection == 0)
			control->trans->projection = 1;
		else
			control->trans->projection = 0;
	}
	draw_map(control->matrix, control->map, control->mlx, control->trans);
	return (0);
}

void	inputs(t_control *control)
{
	mlx_key_hook(control->mlx->mlx_win, key_input, control);
	mlx_hook(control->mlx->mlx_win, 2, 1L<<0, key_close_window, control);
	mlx_hook(control->mlx->mlx_win, 17, 0, close_window, control);
}
