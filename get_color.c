/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:23:25 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 22:23:37 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_light(int start, int end, double percentage)
{
	return (((1.0 - percentage) * start + percentage * end));
}

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int	get_color(t_node node1, t_node node2, t_bressen vars)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (vars.color == node2.color)
		return (node2.color);
	if (vars.dx > vars.dy)
		percentage = percent(node1.x, node2.x, vars.x);
	else
		percentage = percent(node1.y, node2.y, vars.y);
	red = get_light((node1.color >> 16) & 0xFF,
					(node2.color >> 16) & 0xFF,
					percentage);
	green = get_light((node1.color >> 8) & 0xFF,
					(node2.color >> 8) & 0xFF,
					percentage);
	blue = get_light(node1.color & 0xFF,
					node2.color & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}