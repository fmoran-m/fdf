#include "fdf.h"

static void	put_img_pixel(t_data img, int x, int y, int color)
{
	char	*pixel;

	pixel = img.addr + ((img.line_length * y) + ((img.bbp / 8) * x));
	*(unsigned int*) pixel = color;
}

static void	paint_image(t_data img, int color, int x_counter, int y_counter)
{
	int	x;
	int	y;
	int	x_space;
	int	y_space;

	x_space = (SCREEN_WIDTH / 1.2) / x_counter;
	y_space = (SCREEN_HEIGHT / 1.2) / y_counter;
	y = 0;
	while (y <= y_space * y_counter)
	{
		x = 0;
		while (x <= x_space * x_counter)
		{
			put_img_pixel(img, x, y, color);
			x++;
		}
		y = y + y_space;
	}
	x = 0;
	while (x <= x_space * x_counter)
	{
		y = 0;
		while (y <= y_space * y_counter)
		{
			put_img_pixel(img, x, y, color);
			y++;
		}
		x = x + x_space;
	}
}

void	pruebas(int x_counter, int y_counter)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	x_space = (SCREEN_WIDTH / 1.2) / x_counter;
	int y_space = (SCREEN_HEIGHT / 1.2) / y_counter;
	int start_x = (SCREEN_WIDTH - x_space * x_counter) / 2;
	int start_y = (SCREEN_HEIGHT - y_space * y_counter) / 2;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bbp, &img.line_length, &img.endian);
	paint_image(img, MAIN_COLOR, x_counter, y_counter);
	mlx_put_image_to_window(mlx, mlx_win, img.img, start_x, start_y);
	mlx_loop(mlx);
}
