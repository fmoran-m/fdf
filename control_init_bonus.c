#include "fdf.h"

t_control	*control_init(t_map *map, t_mlx *mlx, t_node **mat, t_trans *t)
{
	t_control	*control;

	control = ft_calloc(1, sizeof(t_control));
	if (!control)
		exit_all(map, mat, t, mlx);
	control->map = map;
	control->mlx = mlx;
	control->matrix = mat;
	control->trans = t;
	return (control);
}
