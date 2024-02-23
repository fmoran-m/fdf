#include "fdf.h"

int	close_window(t_loop *loop)
{
	mlx_destroy_window(loop->graphic.mlx, loop->graphic.mlx_win);
	exit(0);
}

int key_close_window(int key, t_loop *loop)
{
	if(key == 53)
	{
		mlx_destroy_window(loop->graphic.mlx, loop->graphic.mlx_win);
		exit(0);
	}
	return (0);
}

void	inputs(t_loop *loop)
{
	mlx_hook(loop->graphic.mlx_win, 17, 0, close_window, loop);
	mlx_hook(loop->graphic.mlx_win, 2, 1L<<0, key_close_window, loop);
}