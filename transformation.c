/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:40 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/08 22:06:05 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static double	min_vector(int width, int height)
{
	double	x;
	double	y;

	x = SCREEN_WIDTH / width / 2;
	y = SCREEN_HEIGHT / height / 2;
	if (x < y)
		return (x);
	else
		return (y);
}

static t_node	scale_position(t_node node, t_trans *trans, t_map *map)
{
	int		x;
	int		y;
	int		range;
	double	z_limit;
	double	zoom;

	range = map->max_z - map->min_z;
	zoom = min_vector(map->width, map->height) + trans->scale;
	x = node.x * zoom;
	y = node.y * zoom;
	x -= (map->width * zoom) / 2;
	y -= (map->height * zoom) / 2;
	if ((map->max_z - map->min_z) != 0)
		z_limit = ((SCREEN_HEIGHT / range) / 5) + trans->z_scale;
	else
		z_limit = (SCREEN_HEIGHT / 5) + trans->z_scale;
	node.z -= map->min_z;
	node.z *= z_limit;
	node.x = x;
	node.y = y;
	return (node);
}

t_node	new_fig(t_node node, t_trans *trans, t_map *map)
{
	int	total_height;

	total_height = (SCREEN_HEIGHT + map->height * (trans->scale / 2)) / 2;
	node = scale_position(node, trans, map);
	node = isometric_perspective(node);
	node.x += SCREEN_WIDTH / 2 + trans->x_pos;
	node.y += total_height + trans->y_pos;
	return (node);
}
