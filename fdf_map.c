#include "fdf.h"

t_node	**fdf_map(t_node **matrix, char *argv, int y_counter, t_mlx graphic)
{
	int		fd;
	int		y;
	int		x_counter;
	char	*line;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	x_counter = count_words(line, ' ');
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
