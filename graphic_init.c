/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:20:49 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/01/08 12:28:01 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx   graphic_init(void)
{
    t_mlx graphic;

    graphic.mlx = mlx_init();
	graphic.mlx_win = mlx_new_window(graphic.mlx, SCREEN_WIDTH, SCREEN_WIDTH, "FDF");
	graphic.img.img = mlx_new_image(graphic.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	graphic.img.addr = mlx_get_data_addr(graphic.img.img, &graphic.img.bbp, &graphic.img.line_length, &graphic.img.endian);
    return (graphic);
}