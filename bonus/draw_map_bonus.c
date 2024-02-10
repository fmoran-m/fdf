/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:23:40 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/10 13:38:20 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_map_bonus(t_node **matrix, t_map *map, t_mlx *mlx, t_trans *trans)
{
	int		i;
	int		j;

	i = 0;
	ft_bzero(mlx->addr, SCREEN_WIDTH * SCREEN_HEIGHT * (mlx->bbp / 8));
	while (i < map->height)
	{
		j = -1;
		while (++j + 1 < map->width)
		{
			bressen(new_fig_bonus(matrix[i][j], trans, map),
				new_fig_bonus(matrix[i][j + 1], trans, map), mlx);
		}
		j = -1;
		if (i > 0)
		{
			while (++j < map->width)
			{
				bressen(new_fig_bonus(matrix[i][j], trans, map),
					new_fig_bonus(matrix[i - 1][j], trans, map), mlx);
			}
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
