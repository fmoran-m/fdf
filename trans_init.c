#include "fdf.h"

t_trans    *trans_init(t_node **matrix, t_map *map)
{
    t_trans *trans;

    trans = ft_calloc(1, sizeof(t_trans));
    if (!trans)
        exit_free_matmap(map, matrix);
    trans->scale = 0;
    trans->z_scale = 1;
    trans->x_pos = 0;
    trans->y_pos = 0;
    trans->x_rot = 0;
    trans->y_rot = 0;
    trans->z_rot = 0;
    return (trans);
}