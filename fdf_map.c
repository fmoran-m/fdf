#include "fdf.h"

static t_node *normalize(t_node *matrix, int max_x, int max_y, int x_counter)
{
	int	i;
	int	x_scale_factor;
	int	y_scale_factor;

	x_scale_factor = SCREEN_WIDTH / max_x;
	y_scale_factor = SCREEN_HEIGHT / max_y;
	i = 0;
	while(i < x_counter)
	{
		matrix[i].x = (matrix[i].x * x_scale_factor);
		matrix[i].y = (matrix[i].y * y_scale_factor);
		i++;
	}
	return (matrix);
}

t_node	**fdf_map(char *argv, t_loop loop)
{
	int			fd;
	char		*line;
	int			max_x;
	int			max_y;

	max_x = 0;
	max_y = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	loop.x_counter = count_words(line, ' ');
	loop.y = 0;
	while (loop.y < loop.y_counter)
	{
		loop.matrix[loop.y] = get_map_line(loop.matrix[loop.y], line, loop.x_counter, loop.y, loop.y_counter, &max_x, &max_y);
		line = get_next_line(fd);
		loop.y++;
	}
	loop.y = 0;
	while (loop.y < loop.y_counter)
	{
		loop.matrix[loop.y] = normalize(loop.matrix[loop.y], max_x, max_y, loop.x_counter);
		paint_image(loop);
		mlx_put_image_to_window(loop.graphic.mlx, loop.graphic.mlx_win, loop.graphic.img.img, 0, 0);
		loop.y++;
	}
	printf("%d, %d\n", max_x, max_y);
	mlx_loop(loop.graphic.mlx);
	close(fd);
	return (loop.matrix);
}
