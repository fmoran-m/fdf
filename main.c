#include "fdf.h"

static void	file_checker(char *argv)
{
	char	*fdf;
	char	*file_type;
	int		i;

	fdf = ".fdf";
	file_type = ft_strrchr(argv, '.');
	if (!file_type || ft_strcmp(fdf, file_type) != 0)
		exit_program(FILE_ERR);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_mlx		*mlx;
	t_node		**matrix;
	t_trans		*trans;
	t_control	*control;

	if (argc != 2)
		exit_program(ARG_ERR);
	file_checker(argv[1]);
	map = map_init();
	map->height = rows_counter(argv[1], map); 
	matrix = (t_node **)ft_calloc(map->height + 1, sizeof(t_node *));
	if (!matrix)
		exit_free_map(MEM_ERR, map);
	matrix = parse_map(argv[1], matrix, map);
	trans = trans_init(matrix, map); 
	mlx = graphic_init(matrix, map, trans);
	draw_map(matrix, map, mlx, trans);
	control = control_init(map, mlx, matrix, trans); //Hacer exit dentro
	printf("entra\n");
	inputs(control);
	mlx_loop(mlx->mlx);
	free(control);
	free_all(map, matrix, trans, mlx);
	return (0);
}
