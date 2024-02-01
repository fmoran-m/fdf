#include "fdf.h"

t_node	*get_map_line(t_node *matrix, char *line, t_map *map, int y)
{
	char		**temp;
	int			x;

	x = 0;
	temp = ft_split(line, ' ');
	if (!temp)
		return (NULL);
	matrix = (t_node *)ft_calloc(map->width + 1, sizeof(t_node));
	if (!matrix)
	{
		free_matrix(temp, map->width);
		return (NULL);
	}
	while (temp[x])
	{
		matrix[x] = read_node(temp[x], x, y, map);
		if (matrix[x].x == -1)
		{
			free_matrix(temp, map->width);
			return (NULL);
		}
		x++;
	}
	free_matrix(temp, map->width);
	return (matrix);
}
