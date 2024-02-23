#include "fdf.h"

void	free_nmatrix(t_node **n_matrix, int y_counter)
{
	int	i;

	i = 0;
	while (i < y_counter)
	{
		free(n_matrix[i]);
		i++;
	}
	free (n_matrix);
}
