#include "fdf.h"

static int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

static int key_close_window(int key, t_mlx *mlx)
{
	if(key == 53)
	{
		//printf("key pressed\n");
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
	return (0);
}

static int scale_up(int key, t_control *control)
{
	if(key == 13)
	{
		control->trans.scale += 100;
		draw_map(control->matrix, control->map, control->mlx, control->trans);
	}
	return (0);
}

void	inputs(t_mlx *mlx, t_trans trans, t_map map, t_node **matrix)
{
	t_control control;
	
	control.mlx = mlx;
	control.map = map;
	control.trans = trans;
	control.matrix = matrix;
	mlx_key_hook(mlx->mlx_win, scale_up, &control);
	mlx_hook(mlx->mlx_win, 2, 1L<<0, key_close_window, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, close_window, mlx);
}