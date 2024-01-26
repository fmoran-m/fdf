#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_mlx		*mlx;
	t_node		**matrix;
	t_trans		*trans;
	t_control	*control;

	if (argc != 2)
		return (-1); //Control de error con perror o strerror
	//Strcmp con el .fdf para comprobar si es correcto
	map = map_init();
	map->height = rows_counter(argv[1]);
	if (!map->height)
		return (0); //Control de errores, error de lectura (Puede hacerse exit)
	matrix = (t_node **)ft_calloc(map->height + 1, sizeof(t_node *));
	if (!matrix) //Control de errores 
		return (-1);
	matrix = parse_map(argv[1], matrix, map);
	trans = trans_init();
	mlx = graphic_init();
	draw_map(matrix, map, mlx, trans);
	control = control_init(map, mlx, matrix, trans);
	inputs(control);
	mlx_loop(mlx->mlx);
	return (0);
}
