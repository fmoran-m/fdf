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
	if (key == Q && !control->trans->z_rot_bool)
		control->trans->z_rot += 0.35;
	if (key == E && !control->trans->z_rot_bool)
		control->trans->z_rot -= 0.35;
	if (key == D && !control->trans->z_rot_bool)
		control->trans->y_rot += 0.35;
	if (key == A && !control->trans->z_rot_bool)
		control->trans->y_rot -= 0.35;
	if (key == W && !control->trans->z_rot_bool)
		control->trans->x_rot += 0.35;
	if (key == S && !control->trans->z_rot_bool)
		control->trans->x_rot -= 0.35;
	return (0);
}

static int	change_elevation(int key, t_control *control)
{
	if (key == F)
		control->trans->z_scale += 0.2;
	if (key == C)
		control->trans->z_scale -= 0.2;
	return (0);
}

static int	constant_rotation(int key, t_control *control)
{
	if (key == J)
	{
		if (!control->trans->z_rot_bool
			|| control->trans->z_rot_bool == -1)
			control->trans->z_rot_bool = 1;
		else
			control->trans->z_rot_bool = 0;
	}
	if (key == K)
		constant_rotation_x(control);
	if (key == L)
		constant_rotation_y(control);
	if (key == U)
		negative_rotation_z(control);
	if (key == I)
		negative_rotation_x(control);
	if (key == O)
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
	if (key == Q || key == W || key == E
		|| key == A || key == S || key == D)
		input_rotation(key, control);
	if (key == F || key == C)
		change_elevation(key, control);
	if (key == R)
		control_reset(control);
	if (key == L || key == J || key == K
		|| key == U || key == I || key == O)
		constant_rotation(key, control);
	if (key == P)
		change_projection(control);
	return (0);
}
