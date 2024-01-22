#include "fdf.h"

t_node	**parse_map(char *argv, t_node **matrix, t_map *map, t_mlx *mlx)
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
		matrix[y] = get_map_line(matrix[y], line, map, y);
		if (matrix[y])
			return (-1); //Control de errores
		line = get_next_line(fd);
		if (!line)
			return (-1); //Control de errores
		y++;
	}
	return (matrix);
}
