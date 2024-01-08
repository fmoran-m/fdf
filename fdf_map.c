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
	graphic.mlx_win = mlx_new_window(graphic.mlx, SCREEN_WIDTH, SCREEN_WIDTH, "FDF");
	graphic.img.img = mlx_new_image(graphic.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	graphic.img.addr = mlx_get_data_addr(graphic.img.img, &graphic.img.bbp, &graphic.img.line_length, &graphic.img.endian);
	y = 0;
	while (y < y_counter)
	{
		matrix[y] =	get_map_line(matrix[y], line, x_counter, y);
		paint_image(graphic.img, matrix, x_counter, y);
		mlx_put_image_to_window(graphic.mlx, graphic.mlx_win, graphic.img.img, 0, 0);
		line = get_next_line(fd);
		y++;
	}
	mlx_loop(graphic.mlx);
	close(fd);
	return (matrix);
}
