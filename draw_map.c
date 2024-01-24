#include "fdf.h"

void    draw_map(t_node **matrix, t_map map, t_mlx *mlx, t_trans trans)
{
    int     i;
    int     j;
    t_node  node1;
    t_node  node2;

    i = 0;
    while (i < map.height)
    {
        j = 0;
        while (j + 1 < map.width)
        {
            node1 = transformation(matrix[i][j], &trans, &map);
            node2 = transformation(matrix[i][j + 1], &trans, &map);
	        printf("no error%d\n", i);
            bressen(node1, node2, mlx);
            j++;
        }
        j = 0;
        if (i > 0)
        {
            while (j < map.width)
            {
                node1 = transformation(matrix[i][j], &trans, &map);
                node2 = transformation(matrix[i - 1][j], &trans, &map);
                bressen(node1, node2, mlx);
                j++;
            }
        }
        i++;
    }
    mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
