#include "fdf.h"

t_node	**fdf_map(char *argv, t_loop loop)
{
	int			fd;
	char		*line;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	loop.x_counter = count_words(line, ' ');
	loop.y = 0;
	while (loop.y < loop.y_counter)
	{
		loop.matrix[loop.y] = get_map_line(loop.matrix[loop.y], line, loop.x_counter, loop.y);
		paint_image(loop.graphic.img, loop.matrix, loop.x_counter, loop.y);
		mlx_put_image_to_window(loop.graphic.mlx, loop.graphic.mlx_win, loop.graphic.img.img, 0, 0);
		line = get_next_line(fd);
		loop.y++;
	}
	mlx_loop(loop.graphic.mlx);
	close(fd);
	return (loop.matrix);
}
