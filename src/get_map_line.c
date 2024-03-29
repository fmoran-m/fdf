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

#include "../fdf.h"

static void	*free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	return (NULL);
}

static void	*free_temp_matrix(char **temp, t_node *matrix)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	free(matrix);
	return (NULL);
}

static void	*free_node(t_node *node)
{
	free(node);
	return (NULL);
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
		return (free_temp(temp));
	matrix = (t_node *)ft_calloc(map->width + 1, sizeof(t_node));
	if (!matrix)
		return (free_temp(temp));
	while (temp[x] && x < map->width
		&& temp[x][0] != '\n' && temp[0][0] != '\n')
	{
		matrix[x] = read_node(temp[x], x, y, map);
		if (matrix[x].x == -1)
			return (free_temp_matrix(temp, matrix));
		x++;
	}
	free_temp(temp);
	if (x < map->width)
		return (free_node(matrix));
	return (matrix);
}
