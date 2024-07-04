/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:38 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 22:24:10 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	rows_counter(char *argv, t_map *map)
{
	int		counter;
	int		fd;
	char	*temp;

	counter = 0;
	fd = open(argv, O_RDONLY);
	temp = get_next_line(fd);
	if (!temp)
	{
		close(fd);
		exit_free_map(READ_ERR, map);
	}
	counter++;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (temp != NULL)
			counter++;
	}
	close (fd);
	return (counter);
}
