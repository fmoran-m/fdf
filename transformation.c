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

	x = SCREEN_WIDTH / width / 3;
	y = SCREEN_HEIGHT / height / 3;
	if (x < y)
		return (x);
	else
		return (y);
}

static t_node	scale_position(t_node node, t_map *map)
{
	int		x;
	int		y;
	int		z;
	double	zoom;

	zoom = min_vector(map->width, map->height);
	x = node.x * zoom;
	y = node.y * zoom;
	z  = node.z * zoom;
	x -= (map->width * zoom) / 2;
	y -= (map->height * zoom) / 2;
	node.x = x;
	node.y = y;
	node.z = z;
	return (node);
}

t_node	new_fig(t_node node, t_trans *trans, t_map *map)
{
	int	total_height;

	total_height = (SCREEN_HEIGHT + map->height * (trans->scale / 2)) / 2;
	node = scale_position(node, map);
	node = isometric_perspective(node);
	node.x += SCREEN_WIDTH / 2 + trans->x_pos;
	node.y += total_height + trans->y_pos;
	return (node);
}
