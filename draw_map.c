#include "fdf.h"

void    draw_map(t_node **matrix, t_map map, t_mlx mlx, t_trans trans)
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
            bressen(node1, node2, &mlx);
            j++;
        }
        i++;
    }
    i = 0;
    j = 0;
}