/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bressen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:19:36 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 22:19:39 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bressen(t_node node1, t_node node2, t_mlx *mlx)
{
	t_bressen	vars;

	vars = bressen_vars_init(node1, node2);
	while (vars.x != node2.x || vars.y != node2.y)
	{
		vars.color = get_color(node1, node2, vars);
		put_img_pixel(mlx, vars.x, vars.y, vars.color);
		vars.err_x += vars.dx;
		if (vars.err_x >= vars.dy)
		{
			vars.err_x -= vars.dy;
			vars.x += vars.sx;
		}
		vars.err_y += vars.dy;
		if (vars.err_y >= vars.dx)
		{
			vars.err_y -= vars.dx;
			vars.y += vars.sy;
		}
	}
}
