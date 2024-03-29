/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:21:55 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/10 13:18:01 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_map(t_node **matrix, t_map *map, t_mlx *mlx)
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
			bressen(new_fig(matrix[i][j], map),
				new_fig(matrix[i][j + 1], map), mlx);
		}
		j = -1;
		if (i > 0)
		{
			while (++j < map->width)
			{
				bressen(new_fig(matrix[i][j], map),
					new_fig(matrix[i - 1][j], map), mlx);
			}
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
