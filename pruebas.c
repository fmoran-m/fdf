/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ /*   Created: 2023/12/05 18:00:43 by fmoran-m          #+#    #+#             */ /*   Updated: 2023/12/05 21:37:30 by fmoran-m         ###   ########.fr       */ /*                                                                            */ /* ************************************************************************** */ 

#include "fdf.h"

static void	put_img_pixel(t_data img, int x, int y, int color)
{
	char *pixel;

	pixel = img.addr + ((img.line_length * y) + ((img.bbp / 8) * x)); //Aritmética de punteros
	*(unsigned int*)pixel = color;
}


static void paint_image(t_data img, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < SCREEN_WIDTH)
	{
	    put_img_pixel(img, x, SCREEN_HEIGHT/2, color);
	    x++;
	}
	while (y < SCREEN_HEIGHT) 
	{
	    put_img_pixel(img, SCREEN_WIDTH/2, y, color);
	    y++;
	}
}

void	pruebas(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bbp, &img.line_length, &img.endian);
	paint_image(img, MAIN_COLOR);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
