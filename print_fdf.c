/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:14 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/12/20 20:54:29 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

void	put_img_pixel(t_data img, int x, int y, int color)
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

static int	bid_y(t_node **n_matrix, int a, int b, int x_space)
{
	int	y;

	y = n_matrix[a][b].y * x_space;
	return (y);
}

static int	rot_x(int old_x, int old_y)
{
	double	theta = (30 * M_PI) / 180;
	int	rotated_x;

	rotated_x = (old_x - old_y) * cos(theta);
	return (rotated_x);
}

static int	rot_y(int old_x, int old_y, int z)
{
	double	theta = (30 * M_PI) / 180;
	int	rotated_y;

	rotated_y = (old_x + old_y - 2 * z) * sin(theta);
	return (rotated_y);
}

static t_node	**rotate_image(t_node **n_matrix, int x_counter, int y_counter)
{
	int	a;
	int	b;
	int	old_x;
	int	old_y;
	int	new_x;
	int	new_y;
	int	x_space;

	a = 0;
	x_space = (SCREEN_WIDTH / 5) / x_counter;
	while (a < y_counter)
	{
		b = 0;
		while (b < x_counter)
		{
			old_x = bid_x(n_matrix, a, b, x_space);
			old_y = bid_y(n_matrix, a, b, x_space);
			new_x = rot_x(old_x, old_y);
			new_y = rot_y(old_x, old_y, n_matrix[a][b].z); 
			n_matrix[a][b].x = new_x;
			n_matrix[a][b].y = new_y;
			b++;
		}
		a++;
	}
	return (n_matrix);
}

static void	paint_image(t_data img, t_node **nm, int x_counter, int y_counter)
{
	int	a0;
	int	a1;
	int	b0;
	int	b1;
	a0 = 0;
	a1 = 1;
	while (a0 < y_counter)
	{
		b0 = 0;
		b1 = 1;
		while (b1 < x_counter)
		{
			bressen(img, nm[a0][b0].x, nm[a0][b1].x, nm[a0][b0].y, nm[a0][b1].y);
			b1++;
			b0++;
		}
		a0++;
	}
	b0 = 0;
	b1 = 1;
	while (b0 < x_counter)
	{
		a0 = 0;
		a1 = 1;
		while (a1 < y_counter)
		{
			bressen(img, nm[a0][b0].x, nm[a1][b0].x, nm[a0][b0].y, nm[a1][b0].y);
			a1++;
			a0++;
		}
		b0++;
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
	n_matrix = rotate_image(n_matrix, x_counter, y_counter);
	paint_image(img, n_matrix, x_counter, y_counter);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
