#include "fdf.h"

int	main(int argc, char **argv)
{
	t_node		**matrix;
	t_mlx		graphic;
	int			y_counter;

	y_counter = 0;
	if (argc != 2)
		return (-1);
	graphic = graphic_init();
	y_counter = rows_counter(argv[1]);
	if (y_counter == 0)
		return (-1);
	matrix = (t_node **)ft_calloc(y_counter + 1, sizeof(t_node *));
	if (!matrix)
		return (-1);
	matrix = fdf_map(matrix, argv[1], y_counter);
	if (!matrix)
		return (-1);
	/*
	for (int i = 0; i < y_counter; i++)
	{
		for (int j = 0; j < x_counter; j++)
			printf("x = %d, y = %d, z = %d, color = %d\n", matrix[i][j].x, matrix[i][j].y, matrix[i][j].z, matrix[i][j].color);
	}
	*/
	free_nmatrix(matrix, y_counter); //Puede que leak en y_counter
//	system("leaks -q fdf");
	return (0);
}
