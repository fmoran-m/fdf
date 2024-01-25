/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:20:49 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/01/23 20:42:28 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx   *graphic_init(void)
{
    t_mlx *mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
    mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bbp, &mlx->line_length, &mlx->endian);
    return (mlx);
}