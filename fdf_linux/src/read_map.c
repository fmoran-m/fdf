/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:34 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 22:24:04 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_node	**read_map(char *argv, t_node **matrix, t_map *map)
{
	int			fd;
	int			y;

	fd = open(argv, O_RDONLY);
	map->temp = get_next_line(fd);
	if (!map->temp)
		exit_free_onlymatmap(matrix, map, &fd);
	map->width = count_words(map->temp, ' ');
	y = 0;
	while (y < map->height)
	{
		matrix[y] = get_map_line(matrix[y], map->temp, map, y);
		if (!matrix[y])
			exit_free_matmap_fd(map, matrix, &fd);
		free(map->temp);
		map->temp = get_next_line(fd);
		y++;
	}
	free(map->temp);
	close(fd);
	return (matrix);
}
