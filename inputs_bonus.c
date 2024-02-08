/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:15:42 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/08 20:15:43 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_window(t_control *control)
{
	mlx_destroy_window(control->mlx->mlx, control->mlx->mlx_win);
	exit(0);
}

static int	key_close_window(int key, t_control *control)
{
	if (key == 53)
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
