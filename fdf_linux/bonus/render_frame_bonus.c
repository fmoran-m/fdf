/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:26:30 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/10 13:27:04 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	render_frame(t_control *control)
{
	if (control->trans->z_rot_bool == 1)
		control->trans->z_rot += 0.05;
	if (control->trans->z_rot_bool == -1)
		control->trans->z_rot -= 0.05;
	if (control->trans->x_rot_bool == 1)
		control->trans->x_rot += 0.05;
	if (control->trans->x_rot_bool == -1)
		control->trans->x_rot -= 0.05;
	if (control->trans->y_rot_bool == 1)
		control->trans->y_rot += 0.05;
	if (control->trans->y_rot_bool == -1)
		control->trans->y_rot -= 0.05;
	draw_map_bonus(control->matrix, control->map, control->mlx, control->trans);
	return (0);
}
