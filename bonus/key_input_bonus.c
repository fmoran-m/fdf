/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:16:31 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/09 17:47:12 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	input_rotation(int key, t_control *control)
{
	if (key == 12 && !control->trans->z_rot_bool)
		control->trans->z_rot += 0.35;
	if (key == 14 && !control->trans->z_rot_bool)
		control->trans->z_rot -= 0.35;
	if (key == 0 && !control->trans->z_rot_bool)
		control->trans->y_rot += 0.35;
	if (key == 2 && !control->trans->z_rot_bool)
		control->trans->y_rot -= 0.35;
	if (key == 13 && !control->trans->z_rot_bool)
		control->trans->x_rot += 0.35;
	if (key == 1 && !control->trans->z_rot_bool)
		control->trans->x_rot -= 0.35;
	return (0);
}

static int	change_elevation(int key, t_control *control)
{
	if (key == 3)
		control->trans->z_scale += 0.2;
	if (key == 8)
		control->trans->z_scale -= 0.2;
	return (0);
}

static int	constant_rotation(int key, t_control *control)
{
	if (key == 38)
	{
		if (!control->trans->z_rot_bool
			|| control->trans->z_rot_bool == -1)
			control->trans->z_rot_bool = 1;
		else
			control->trans->z_rot_bool = 0;
	}
	if (key == 40)
		constant_rotation_x(control);
	if (key == 37)
		constant_rotation_y(control);
	if (key == 32)
		negative_rotation_z(control);
	if (key == 34)
		negative_rotation_x(control);
	if (key == 31)
		negative_rotation_y(control);
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
	if (key == 12 || key == 13 || key == 14
		|| key == 0 || key == 1 || key == 2)
		input_rotation(key, control);
	if (key == 3 || key == 8)
		change_elevation(key, control);
	if (key == 15)
		control_reset(control);
	if (key == 37 || key == 38 || key == 40
		|| key == 32 || key == 34 || key == 31)
		constant_rotation(key, control);
	if (key == 35)
		change_projection(control);
	return (0);
}
