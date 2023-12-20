#include "fdf.h"

void	bressen(t_data img, int x0, int x1, int y0, int y1)
{
	int	x_vector;
	int	y_vector;
	int	x_sen;
	int	y_sen;
	int	error;
	
	x_sen = 0;
	y_sen = 0;
	x_vector = x1 - x0;
	y_vector = y1 - y0;
	error = 0;

	if (x_vector > 0)
		x_sen = 1;
	else if (x_vector < 0)
		x_sen = -1;
	if (y_vector > 0)
		y_sen = 1;
	else if (y_vector < 0)
		y_sen = -1;
	if (x_vector < 0)
		x_vector = -x_vector;
	if (y_vector < 0)
		y_vector = -y_vector;
	if (x_vector > y_vector)
	{
		error = 2 * y_vector - x_vector; 
		while (x0 < x1 && y0 < y1)
		{
			put_img_pixel(img, x0, y0, MAIN_COLOR);
			if (error >= 0)
			{
				y0 = y0 + y_sen;
				error -= 2 * x_vector; 
			}
			x0 = x0 + x_sen;
			error += y_vector;
		}
	}
	else
	{
		error = 2 * y_vector - x_vector; 
		while (x0 < x1 && y0 < y1)
		{
			put_img_pixel(img, x0, y0, MAIN_COLOR);
			if (error >= 0)
			{
				x0 = x0 + x_sen;
				error -= 2 * y_vector; 
			}
			y0 = y0 + y_sen;
			error += y_vector;
		}
	}
	put_img_pixel(img, x1, y1, MAIN_COLOR);
}
