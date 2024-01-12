#include "fdf.h"

t_node	*get_map_line(t_node *matrix, char *line, int x_counter, int y, int y_counter)
{
	char		**temp;
	int			i;

	i = 0;
	temp = ft_split(line, ' ');
	matrix = (t_node *)ft_calloc(x_counter + 1, sizeof(t_node));
	while (temp[i])
	{
		matrix[i] = parse_line(temp[i], i, y, x_counter, y_counter);
		//printf("%d, %d\n", matrix[i].x, matrix[i].y);
		i++;
	}
	free_matrix(temp, x_counter);
	return (matrix);
}