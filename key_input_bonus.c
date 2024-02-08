/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:16:31 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/08 17:27:03 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	input_rotation(int key, t_control *control)
{
	if (key == 6 && !control->trans->z_rot_bool)
		control->trans->z_rot += 0.05;
	if (key == 8 && !control->trans->z_rot_bool)
		control->trans->y_rot += 0.05;
	if (key == 7 && !control->trans->z_rot_bool)
		control->trans->x_rot += 0.05;
	return (0);
}

static int	change_elevation(int key, t_control *control)
{
	if (key == 3)
		control->trans->z_scale += 1;
	if (key == 9)
		control->trans->z_scale -= 1;
	return (0);
}

static int	constant_rotation(int key, t_control *control)
{
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
	return (0);
}

static int	change_projection(t_control *control)
{
	control_reset(control);
	if (control->trans->projection == 0)
		control->trans->projection = 1;
	else
		control->trans->projection = 0;
	return (0);
}

int	key_input(int key, t_control *control)
{
	if (key == 6 || key == 7 || key == 8)
		input_rotation(key, control);
	if (key == 3 || key == 9)
		change_elevation(key, control);
	if (key == 15)
		control_reset(control);
	if (key == 37 || key == 38 || key == 40)
		constant_rotation(key, control);
	if (key == 35)
		change_projection(control);
	return (0);
}
