#include "fdf.h"

int	main(int argc, char **argv)
{
	t_loop		loop;

	loop.y_counter = 0;
	if (argc != 2)
		return (-1);
	loop.graphic = graphic_init();
	loop.y_counter = rows_counter(argv[1]);
	if (loop.y_counter == 0)
		return (-1);
	loop.matrix = (t_node **)ft_calloc(loop.y_counter + 1, sizeof(t_node *));
	if (!loop.matrix)
		return (-1);
	loop.matrix = fdf_map(argv[1], loop);
	if (!loop.matrix)
		return (-1);
	free_nmatrix(loop.matrix, loop.y_counter); //Puede que leak en y_counter
	return (0);
}
