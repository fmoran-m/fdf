#include "fdf.h"

static t_node	*normalize_line(t_node *matrix, int x_counter, int max_x, int min_x, int max_y, int min_y) //Debo controlar todas la direcciones
{
	int	new_origin_x;
	int	new_origin_y;
	int	i;

	new_origin_x = (max_x - min_x) / 2;
	new_origin_y = (max_y - min_y) / 2;
	//new_origin_y = 0;
	i = 0;
	while (i < x_counter)
	{
		matrix[i].x -= new_origin_x;
		matrix[i].y += new_origin_y;
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
	int			min_x;
	int			min_y;

	min_y = SCREEN_HEIGHT;
	min_x = SCREEN_WIDTH;
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
		loop.matrix[loop.y] = get_map_line(loop.matrix[loop.y], line, loop.x_counter, loop.y, loop.y_counter, &max_x, &max_y, &min_x, &min_y);
		line = get_next_line(fd);
		loop.y++;
	}
	loop.y = 0;
	while (loop.y < loop.y_counter)
	{
		loop.matrix[loop.y] = normalize_line(loop.matrix[loop.y], loop.x_counter, max_x, min_x, max_y, min_y);
		paint_image(loop);
		mlx_put_image_to_window(loop.graphic.mlx, loop.graphic.mlx_win, loop.graphic.img.img, 0, 0);
		loop.y++;
	}
	printf("Max_x = %d, Max_y = %d\n", max_x, max_y);
	printf("Min_x = %d, Min_y = %d\n", min_x, min_y);
	mlx_loop(loop.graphic.mlx);
	close(fd);
	return (loop.matrix);
}
