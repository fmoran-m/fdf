#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	t_node	**matrix;

	if (argc != 2)
		return (-1); //Control de error con perror o strerror
	//Strcmp con el .fdf para comprobar si es correcto
	mlx = graphic_init();
	map_init(&map);
	map->height = rows_counter(argv[1]);
	if (!map->height)
		return (-1); //Control de errores, error de lectura (Puede hacerse exit)
	matrix = (t_node **)ft_calloc(loop.y_counter + 1, sizeof(t_node *));
	if (!loop.matrix) //Control de errores 
		return (-1);
	matrix = fdf_map(argv[1], matrix, map, mlx);
	//print_image
	//inputs();
	//mlx_loop(mlx);
	if (!loop.matrix)
		return (-1);
	free_nmatrix(loop.matrix, loop.y_counter); //Puede que leak en y_counter
	return (0);
}
