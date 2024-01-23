#include "fdf.h"

t_node	*get_map_line(t_node *matrix, char *line, t_map *map, int y)
{
	char		**temp;
	int			x;

	x = 0;
	temp = ft_split(line, ' ');
	matrix = (t_node *)ft_calloc(map->width + 1, sizeof(t_node));
	while (temp[x])
	{
		matrix[x] = parse_line(temp[x], x, y, map);
		x++;
	}
	free_matrix(temp, map->height);
	return (matrix);
}
