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

static int	inter_color(int start, int end, double relative)
{
	int color;
	int start_color;
	int	end_color;

	start_color = (1 - relative) * start;
	end_color = relative * end;
	color = start_color + end_color;
	return (color);
}

static double	get_relative(int start, int end, int current)
{
	double	position;
	double	total;
	double	relative;

	position = current - start;
	total = end - start;
	relative = position / total;
	return (relative);
}

int	get_color(t_node node1, t_node node2, t_bressen vars)
{
	int		red;
	int		green;
	int		blue;
	double	relative;

	if (vars.color == node2.color)
		return (node2.color);
	if (vars.dx > vars.dy)
		relative = get_relative(node1.x, node2.x, vars.x);
	else
		relative = get_relative(node1.y, node2.y, vars.y);
	red = inter_color(get_red(node1.color), get_red(node2.color), relative);
	green = inter_color(get_green(node1.color), get_green(node2.color), relative);
	blue = inter_color(get_blue(node1.color), get_blue(node2.color), relative);
	return ((red << 16) | (green << 8) | blue);
}