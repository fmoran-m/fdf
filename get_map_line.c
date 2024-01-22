#include "fdf.h"

t_node	*get_map_line(t_node *matrix, char *line, t_map **map, int y)
{
	char		**temp;
	int			x;

	x = 0;
	temp = ft_split(line, ' ');
	if (!temp)
		return (-1); //Controlamos errores
	matrix = (t_node *)ft_calloc(map->height + 1, sizeof(t_node));
	if (!matrix)
		return (-1) //Controlamos errores
	while (temp[x])
	{
		matrix[x] = parse_line(temp[x], x, y, map);
		x++;
	}
	free_matrix(temp, map->height);
	return (matrix);
}
