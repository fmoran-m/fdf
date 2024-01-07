/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:14 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/01/02 18:11:00 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

void	put_img_pixel(t_data img, int x, int y, int color)
{
	char	*pixel;

	pixel = img.addr + ((img.line_length * y) + ((img.bbp / 8) * x));
	*(unsigned int*) pixel = color;
}
/*
static int	bid_x(t_node **n_matrix, int a, int b, int x_space)
{
	int	x;

	x = n_matrix[a][b].x * x_space;
	return (x);
}

static int	bid_y(t_node **n_matrix, int a, int b, int x_space)
{
	int	y;

	y = n_matrix[a][b].y * x_space;
	return (y);
}

static int	rot_x(int x, int y)
{
	double	theta = (-90 * M_PI) / 180;
	int	rotated_x;

	rotated_x = (x * cos(theta)) - (y * sin(theta));
	return (rotated_x);
}

static int	rot_y(int x, int y)
{
	double	theta = (-90 * M_PI) / 180;
	int		rotated_y;

	rotated_y = (x * sin(theta)) + (y * cos(theta)) + 800;
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
	double	theta = (30 * M_PI) / 180;

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
			new_y = rot_y(old_x, old_y); 
			int last_x = (new_x * cos(theta)) - (new_y * cos(theta));
			int last_y = (new_x * sin(theta)) + (new_y * sin(theta)) - n_matrix[a][b].z;
			n_matrix[a][b].x = last_x;
			n_matrix[a][b].y = last_y;
			printf("%d, %d\n", new_x, new_y);
			b++;
		}
		a++;
	}
	return (n_matrix);
}
*/
void	paint_image(t_data img, t_node **nm, int x_counter, int y)
{
	int	x0;
	int	x1;

	x0 = 0;
	x1 = 1;
	while (x1 < x_counter)
	{
		bressen(img, nm[y][x0].x, nm[y][x1].x, nm[y][x0].y, nm[y][x1].y);
		x0++;
		x1++;
	}
}