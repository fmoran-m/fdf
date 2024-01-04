#include "fdf.h"

void	free_matrix(char **matrix, int y_counter)
{
	int	i;

	i = 0;
	while (i < y_counter)
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}