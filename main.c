#include "fdf.h"

int	main(int argc, char **argv)
{
	int			y_counter;
	t_node		**matrix;

	y_counter = 0;
	if (argc != 2)
		return (-1);
	y_counter = rows_counter(argv[1]);
	if (y_counter == 0)
		return (0);
	matrix = (t_node **)ft_calloc(y_counter + 1, sizeof(t_node *));
	if (!matrix)
		return (-1);
	matrix = fdf_map(matrix, argv[1], y_counter);
	/*
	x_counter = count_words(matrix[0], ' ');
	n_matrix = massive_atoi(matrix, y_counter, x_counter);
	free_matrix(matrix, y_counter); //Puede que leak en pasar y_counter
	for (int i = 0; i < y_counter; i++)
	{
		for (int j = 0; j < x_counter; j++)
			printf("x = %d, y = %d, z = %d, color = %d\n", n_matrix[i][j].x, n_matrix[i][j].y, n_matrix[i][j].z, n_matrix[i][j].color);
	}
	print_fdf(x_counter, y_counter, n_matrix);
	free_nmatrix(n_matrix, y_counter); //Puede que leak en y_counter
//	system("leaks -q fdf");
*/
	return (0);
}
