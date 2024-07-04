/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_reset_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:14:45 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/08 22:10:40 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	control_reset(t_control *control)
{
	control->trans->scale = 1;
	control->trans->z_scale = 1;
	control->trans->x_pos = 0;
	control->trans->y_pos = 0;
	control->trans->x_rot = 0;
	control->trans->y_rot = 0;
	control->trans->z_rot = 0;
	control->trans->x_rot_bool = 0;
	control->trans->y_rot_bool = 0;
	control->trans->z_rot_bool = 0;
}
