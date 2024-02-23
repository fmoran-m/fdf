/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant_rotation_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:01 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/08 21:43:19 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	constant_rotation_x(t_control *control)
{
	if (!control->trans->x_rot_bool
		|| control->trans->x_rot_bool == -1)
		control->trans->x_rot_bool = 1;
	else
		control->trans->x_rot_bool = 0;
}

void	constant_rotation_y(t_control *control)
{
	if (!control->trans->y_rot_bool
		|| control->trans->y_rot_bool == -1)
		control->trans->y_rot_bool = 1;
	else
		control->trans->y_rot_bool = 0;
}

void	negative_rotation_z(t_control *control)
{
	if (!control->trans->z_rot_bool
		|| control->trans->z_rot_bool == 1)
		control->trans->z_rot_bool = -1;
	else
		control->trans->z_rot_bool = 0;
}

void	negative_rotation_x(t_control *control)
{
	if (!control->trans->x_rot_bool
		|| control->trans->x_rot_bool == 1)
		control->trans->x_rot_bool = -1;
	else
		control->trans->x_rot_bool = 0;
}

void	negative_rotation_y(t_control *control)
{
	if (!control->trans->y_rot_bool
		|| control->trans->y_rot_bool == 1)
		control->trans->y_rot_bool = -1;
	else
		control->trans->y_rot_bool = 0;
}
