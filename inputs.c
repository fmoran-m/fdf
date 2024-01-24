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
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
	return (0);
}

void	inputs(t_mlx *mlx)
{
	t_control control;

	mlx_hook(mlx->mlx_win, 17, 0, close_window, mlx);
	mlx_hook(mlx->mlx_win, 2, 1L<<0, key_close_window, mlx);
}