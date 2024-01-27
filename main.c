#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_mlx		*mlx;
	t_node		**matrix;
	t_trans		*trans;
	t_control	*control;

	if (argc != 2)
	{
		ft_putendl_fd("Incorrect number of arguments. This function requires exactly 1 argument.", 2);
		exit(-1);
	}
	//Strcmp con el .fdf para comprobar si es correcto
	map = map_init(); //exit si falla la memoria
	map->height = rows_counter(argv[1]); //exit, ojo con los fd
	matrix = (t_node **)ft_calloc(map->height + 1, sizeof(t_node *)); //exit si falla la reserva
	if (!matrix)
		return(-1);
	matrix = parse_map(argv[1], matrix, map); //Reservas y lecturas,  mucho ojo
	trans = trans_init(); //exit reserva de memoria
	mlx = graphic_init(); //exit reserva de memoria
	draw_map(matrix, map, mlx, trans);
	control = control_init(map, mlx, matrix, trans); //exit en la reserva
	inputs(control);
	mlx_loop(mlx->mlx);
	return (0);
}
