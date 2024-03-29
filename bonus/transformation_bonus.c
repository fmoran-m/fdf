/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:15:54 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/09 22:29:08 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_node	isometric_perspective(t_node node)
{
	double	theta;
	int		x;
	int		y;

	theta = (30 * M_PI) / 180;
	x = (node.x * cos(theta)) - (node.y * cos(theta));
	y = ((node.x * sin(theta)) + (node.y * sin(theta)) - node.z);
	node.x = x;
	node.y = y;
	return (node);
}

double	min_vector(int width, int height)
{
	double	x;
	double	y;

	x = SCREEN_WIDTH / width / 3;
	y = SCREEN_HEIGHT / height / 3;
	if (x < y)
		return (x);
	else
		return (y);
}

static t_node	scale_position(t_node node, t_trans *trans, t_map *map)
{
	int		x;
	int		y;
	int		z;
	double	zoom;

	zoom = (min_vector(map->width, map->height) + 1) * trans->scale;
	x = node.x * zoom;
	y = node.y * zoom;
	z = (node.z * zoom) * trans->z_scale;
	x -= (map->width * zoom) / 2;
	y -= (map->height * zoom) / 2;
	node.z = z;
	node.x = x;
	node.y = y;
	return (node);
}

static t_node	cavalier_perspective(t_node node)
{
	int	x;
	int	y;

	x = node.x - (1 / 2 * node.z);
	y = node.y - (1 / 2 * node.z);
	node.x = x;
	node.y = y;
	return (node);
}

t_node	new_fig_bonus(t_node node, t_trans *trans, t_map *map)
{
	int	total_height;

	if (trans->projection == 1)
		trans->x_rot_k = 1.0472;
	else
		trans->x_rot_k = 0;
	node = scale_position(node, trans, map);
	node = rot_x(node, trans);
	node = rot_y(node, trans);
	node = rot_z(node, trans);
	if (trans->projection == 1)
		node = cavalier_perspective(node);
	if (trans->projection == 0)
		node = isometric_perspective(node);
	total_height = (SCREEN_HEIGHT * trans->scale) / 2;
	node.x += SCREEN_WIDTH / 2 + trans->x_pos;
	node.y += total_height + trans->y_pos;
	return (node);
}
