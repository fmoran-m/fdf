/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:14 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/01/15 00:58:09 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

void	put_img_pixel(t_data img, int x, int y, int color)
{
	char	*pixel;

	if (!color)
		color = MAIN_COLOR;
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		pixel = img.addr + ((img.line_length * y) + ((img.bbp / 8) * x));
		*(unsigned int*) pixel = color;
	}
}


void	paint_image(t_loop loop)
{
	int	x0;
	int	x1;

	x0 = 0;
	x1 = 1;
	while (x1 < loop.x_counter)
	{
		bressen(loop.graphic.img, loop.matrix[loop.y][x0].x, loop.matrix[loop.y][x1].x, loop.matrix[loop.y][x0].y, loop.matrix[loop.y][x1].y, loop.matrix[loop.y][x0].color, loop.matrix[loop.y][x1].color);
		x0++;
		x1++;
	}
	x0 = 0;
	if (loop.y > 0)
	{
		while (x0 < loop.x_counter)
		{
			bressen(loop.graphic.img, loop.matrix[loop.y][x0].x, loop.matrix[loop.y - 1][x0].x, loop.matrix[loop.y][x0].y, loop.matrix[loop.y - 1][x0].y, loop.matrix[loop.y][x0].color, loop.matrix[loop.y][x1].color);
			x0++;
		}
	}
}
