/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:14 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/12/19 17:20:21 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

static void	put_img_pixel(t_data img, int x, int y, int color)
{
	char	*pixel;

	pixel = img.addr + ((img.line_length * y) + ((img.bbp / 8) * x));
	*(unsigned int*) pixel = color;
}

static int	bid_x(t_node **n_matrix, int a, int b, int x_space)
{
	int	x;

	x = n_matrix[a][b].x * x_space + 400;
	return (x);
}

static int	bid_y(t_node **n_matrix, int a, int b, int y_space)
{
	int	y;

	y = n_matrix[a][b].y * y_space + 400;
	return (y);
}

static int	rot_x(int old_x, int old_y)
{
	double	theta = (30 * M_PI) / 180;
	int	rotated_x;

	rotated_x = (cos(theta) * old_x) - (sin(theta) * old_y);
	return (rotated_x);
}

static int	rot_y(int old_x, int old_y)
{
	double	theta = (30 * M_PI) / 180;
	int	rotated_y;

	rotated_y = (sin(theta) * old_x) + (cos(theta) * old_y);
	return (rotated_y);
}

static void	paint_image(t_data img, t_node **n_matrix, int x_counter, int y_counter)
{
	int	a;
	int	b;
	int	old_x;
	int	old_y;
	int	new_x;
	int	new_y;
	int	x_space;
	int	y_space;

	a = 0;
	x_space = (SCREEN_WIDTH / 5) / x_counter;
	y_space = (SCREEN_HEIGHT / 5) / y_counter;
	while (a < y_counter)
	{
		b = 0;
		while (b < x_counter)
		{
			old_x = bid_x(n_matrix, a, b, x_space);
			old_y = bid_y(n_matrix, a, b, y_space);
			new_x = rot_x(old_x, old_y);
			new_y = rot_y(old_x, old_y); 
			put_img_pixel(img, new_x, new_y, MAIN_COLOR); 
			b++;
		}
		a++;
	}
}

void	print_fdf(int x_counter, int y_counter, t_node **n_matrix)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
//	int x_space = (SCREEN_WIDTH / 1.2) / x_counter;
//	int y_space = (SCREEN_HEIGHT / 1.2) / y_counter;
//	int start_x = (SCREEN_WIDTH - x_space * x_counter) / 2;
///	int start_y = (SCREEN_HEIGHT - y_space * y_counter) / 2;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bbp, &img.line_length, &img.endian);
	paint_image(img, n_matrix, x_counter, y_counter);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
