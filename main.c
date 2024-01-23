#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	t_node	**matrix;
	t_trans	*trans;

	if (argc != 2)
		return (-1); //Control de error con perror o strerror
	//Strcmp con el .fdf para comprobar si es correcto
	mlx = graphic_init();
	map = map_init();
	map->height = rows_counter(argv[1]);
	if (!map->height)
		return (-1); //Control de errores, error de lectura (Puede hacerse exit)
	matrix = (t_node **)ft_calloc(map->height + 1, sizeof(t_node *));
	if (!matrix) //Control de errores 
		return (-1);
	matrix = parse_map(argv[1], matrix, map);
	trans = trans_init();
	draw_map(matrix, mlx, map, trans);
	//inputs();
	//mlx_loop(mlx);
	return (0);
}
