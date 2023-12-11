/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:04:16 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/12/11 04:04:58 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_lstnew_map(int x_counter, int y_counter, int z_value, int color)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (new == NULL)
		return (NULL);
	new->x = x_counter;
	new->y = y_counter;
	new->z = z_value;
	new->color = color;
	new->next = 0;
	return (new);
}
