/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:14 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/08 15:43:19 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

void	put_img_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	if (!color)
		color = MAIN_COLOR;
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		pixel = mlx->addr + ((mlx->line_length * y) + ((mlx->bbp / 8) * x));
		*(unsigned int *)pixel = color;
	}
}
