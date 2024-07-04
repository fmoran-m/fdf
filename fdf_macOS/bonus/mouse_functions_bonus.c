/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:13:47 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/09 17:26:42 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	mouse_press(int key, int x, int y, t_control *control)
{
	if (key == 1 && x < SCREEN_WIDTH && x > 0
		&& y < SCREEN_HEIGHT && y > 0)
		control->trans->mouse_pressed = 1;
	if (key == 4)
		control->trans->scale += 0.2;
	if (key == 5)
		control->trans->scale -= 0.2;
	if (control->trans->scale < 0.2)
		control->trans->scale = 0.2;
	control->trans->last_x = x;
	control->trans->last_y = y;
	return (0);
}

int	mouse_hold(int x, int y, t_control *control)
{
	if (control->trans->mouse_pressed == 0)
		return (0);
	control->trans->x_pos += (x - control->trans->last_x);
	control->trans->y_pos += (y - control->trans->last_y);
	control->trans->last_x = x;
	control->trans->last_y = y;
	return (0);
}

int	mouse_release(int key, int x, int y, t_control *control)
{
	x = 0;
	y = 0;
	key = 0;
	control->trans->mouse_pressed = x;
	control->trans->mouse_pressed = y;
	control->trans->mouse_pressed = key;
	return (0);
}
