#include "fdf.h"

void	draw_map(t_node **matrix, t_mlx *mlx, t_map *map, t_trans *trans)
{
    int i;

    i = 0;
    while (i < map->width)
    {
        draw_line(matrix[i], map, mlx, trans);
        i++;
    }
    mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}