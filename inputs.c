/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:25:32 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/01/31 19:00:39 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	mouse_press(int key, int x, int y, t_control *control)
{
	(void)x;
	(void)y;
	if (key == 1)
		control->trans->mouse_pressed = 1;
	if (key == 4)
		control->trans->scale += 1;
	if (key == 5)
		control->trans->scale -= 1;
	control->trans->last_x = x;
	control->trans->last_y = y;
	draw_map(control->matrix, control->map, control->mlx, control->trans);
	return (0);
}

static int	mouse_hold(int x, int y, t_control *control)
{
	if (control->trans->mouse_pressed == 0)
		return (0);
	control->trans->x_pos += (x - control->trans->last_x);
	control->trans->y_pos += (y - control->trans->last_y);
	control->trans->last_x = x;
	control->trans->last_y = y;
	draw_map(control->matrix, control->map, control->mlx, control->trans);
	return (0);
}

static int	mouse_release(int key, int x, int y, t_control *control)
{
	control->trans->mouse_pressed = 0;
	if (key == 1)
	//printf("%d\n", control->trans->mouse_pressed);
	draw_map(control->matrix, control->map, control->mlx, control->trans);
	return (0);
}

static int	key_input(int key, t_control *control)
{
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
	if (key == 9)
		control->trans->z_scale -= 1;
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
	printf("%d\n", control->trans->mouse_pressed);
	mlx_hook(control->mlx->mlx_win, 4, 0, mouse_press, control);
	mlx_hook(control->mlx->mlx_win, 6, 0, mouse_hold, control);
	mlx_hook(control->mlx->mlx_win, 5, 0, mouse_release, control);
	mlx_hook(control->mlx->mlx_win, 3, 0, key_input, control);
	mlx_hook(control->mlx->mlx_win, 2, 0, key_close_window, control);
	mlx_hook(control->mlx->mlx_win, 17, 0, close_window, control);
}
