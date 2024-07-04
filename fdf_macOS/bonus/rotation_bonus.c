/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:13:55 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/08 22:08:20 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_node	rot_z(t_node node, t_trans *trans)
{
	int		x;
	int		y;
	double	theta;

	theta = trans->z_rot;
	x = node.x * cos(theta) - node.y * sin(theta);
	y = node.x * sin(theta) + node.y * cos(theta);
	node.x = x;
	node.y = y;
	return (node);
}

t_node	rot_y(t_node node, t_trans *trans)
{
	int		x;
	int		z;
	double	theta;

	theta = trans->y_rot;
	x = node.x * cos(theta) + node.z * sin(theta);
	z = -node.x * sin(theta) + node.z * cos(theta);
	node.x = x;
	node.z = z;
	return (node);
}

t_node	rot_x(t_node node, t_trans *trans)
{
	int		y;
	int		z;
	double	theta;

	theta = trans->x_rot + trans->x_rot_k;
	y = node.y * cos(theta) - node.z * sin(theta);
	z = node.y * sin(theta) + node.z * cos(theta);
	node.y = y;
	node.z = z;
	return (node);
}
