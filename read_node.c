/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:36 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/06 04:00:46 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_node	intro_node_data(int x, int y, char *temp, int color)
{
	t_node	new;

	new.x = x;
	new.y = y;
	new.z = ft_atoi(temp);
	new.color = color;
	return (new);
}

static void update_map_z_values(t_map *map, int z)
{
	if (z > map->max_z)
		map->max_z = z;
	if (z < map->min_z)
		map->min_z = z;
}

t_node	read_node(char *temp, int x, int y, t_map *map)
{
	int		i;
	int		color;
	t_node	new;

	i = 0;
	color = 0;
	while (temp[i] && temp[i] != ',') // ¿Qué pasa si i+1 no es nada?
	{
		if (!isxdigit_fdf(temp[i]))
		{
			new.x = -1;
			return (new);
		}
		i++;
	}
	if (temp[i] == ',')
	{
		i++;
		color = ft_atoi_base(&temp[i], 16);
	}
	new = intro_node_data(x, y, temp, color);
	update_map_z_values(map, new.z);
	return (new);
}
