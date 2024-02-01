/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:36 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 22:24:07 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node	read_node(char *temp, int x, int y, t_map *map)
{
	int		i;
	int		color;
	t_node	new;

	i = 0;
	color = 0;
	new.x = x;
	new.z = ft_atoi(temp);
	new.y = y;
	while (temp[i] && temp[i] != ',')
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
		color = ft_atoi_base(&temp[i]);
	}
	new.color = color;
	return (new);
}
