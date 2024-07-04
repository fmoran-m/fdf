/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:25:32 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 18:02:37 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

static int	key_close_window(int key, t_mlx *mlx)
{
	if (key == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
	return (0);
}

void	esc_inputs(t_mlx *mlx)
{
	mlx_hook(mlx->mlx_win, 2, (1L << 0), key_close_window, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, close_window, mlx);
}
