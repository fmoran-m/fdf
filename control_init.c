#include "fdf.h"

t_control	*control_init(t_map *map, t_mlx *mlx, t_node **matrix, t_trans *trans)
{
	t_control *control;

	control = ft_calloc(1, sizeof(t_control));
	if (!control)
		exit_all(map, matrix, trans, mlx);
	control->map = map;
	control->mlx = mlx;
	control->matrix = matrix;
	control->trans = trans;
	return (control);
}