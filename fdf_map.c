#include "fdf.h"

t_node	**fdf_map(char *argv, t_node *matrix, t_map *map, t_mlx mlx)
{
	int			fd;
	char		*line;
	int			y;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (NULL); //Controlamos errores, liberamos y hacemos exit
	map->width = count_words(line, ' ');
	y = 0;
	while (y < map->height)
	{
		matrix[y] = get_map_line(matrix[y], line, &map, y);
		if (matrix[y])
			return (-1); //Control de errores
		line = get_next_line(fd);
		if (!line)
			return (-1); //Control de errores
		y++;
	} //NOS QUEDAMOS POR AQUÍ
	printf("Max_x = %d, Max_y = %d\n", max_x, max_y);
	printf("Min_x = %d, Min_y = %d\n", min_x, min_y);
	y = 0;
	while (y < loop.y_counter)
	{
		paint_image(loop);
		mlx_put_image_to_window(loop.graphic.mlx, loop.graphic.mlx_win, loop.graphic.img.img, 0, 0);
		y++;
	}
	inputs(&loop);
	mlx_loop(loop.graphic.mlx);
	close(fd);
	return (loop.matrix);
}
