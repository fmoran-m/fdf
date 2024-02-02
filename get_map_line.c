/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:22 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 22:23:41 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void free_temp(char **temp)
{
	int i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

t_node	*get_map_line(t_node *matrix, char *line, t_map *map, int y)
{
	char		**temp;
	int			x;

	x = 0;
	temp = ft_split(line, ' ');
	if (!temp)
		return (NULL);
	if (temp[0][0] == '\n')
	{
		free_temp(temp);
		return (NULL);
	}
	matrix = (t_node *)ft_calloc(map->width + 1, sizeof(t_node));
	if (!matrix)
	{
		free_temp(temp);
		free(matrix);
		return (NULL);
	}
	while (temp[x] && x < map->width)
	{
		matrix[x] = read_node(temp[x], x, y, map);
		if (matrix[x].x == -1)
		{
			free_temp(temp);
			free(matrix);
			return (NULL);
		}
		x++;
	}
	free_temp(temp);
	if (x < map->width)
	{
		free(matrix);
		return (NULL);
	}
	return (matrix);
}
