#include "fdf.h"

t_node	**fdf_map(t_node **matrix, char *argv, int y_counter)
{
	int		fd;
	int		y;
	int		x_counter;
	char	*line;
	t_mlx	graphic;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	x_counter = count_words(line, ' ');
	graphic.mlx = mlx_init();
	graphic.mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_WIDTH, "FDF");
	graphic.img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	graphic.img.addr = mlx_get_data_addr(graphic.img.img, &graphic.img.bbp, &graphic.img.line_length, &graphic.img.endian);
	mlx_loop(graphic.mlx);
	while (y < y_counter)
	{
		matrix[y] =	get_map_line(matrix[y], line, x_counter, y);
		paint_image(graphic.img, matrix, y, x_counter);
		line = get_next_line(fd);
		y++;
	}
	return (matrix);
}
	/*
	matrix[i] = get_map_line(matrix[i], line, x_counter, y);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			matrix[i] = get_map_line(matrix[i], line, x_counter, y);
			y++;
			i++;
		}
	}
	close(fd);
	return (matrix);
}
*/