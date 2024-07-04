/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:25:10 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/09 17:39:40 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_program(MEM_ERR);
	map->temp = NULL;
	map->max_z = INT_MIN;
	map->min_z = INT_MAX;
	map->width = 0;
	map->height = 0;
	return (map);
}

t_trans	*trans_init(t_node **matrix, t_map *map)
{
	t_trans	*trans;

	trans = ft_calloc(1, sizeof(t_trans));
	if (!trans)
		exit_free_matmap(map, matrix);
	trans->scale = 1;
	trans->z_scale = 1;
	trans->x_pos = 0;
	trans->y_pos = 0;
	trans->x_rot = 0;
	trans->y_rot = 0;
	trans->z_rot = 0;
	trans->x_rot_bool = 0;
	trans->y_rot_bool = 0;
	trans->z_rot_bool = 0;
	trans->projection = 0;
	trans->x_rot_k = 0;
	trans->x_mouse = 0;
	trans->y_mouse = 0;
	trans->mouse_pressed = 0;
	return (trans);
}

t_mlx	*graphic_init(t_node **matrix, t_map *map, t_trans *trans)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		exit_free_matmaptrans(map, matrix, trans);
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bbp,
			&mlx->line_length, &mlx->endian);
	return (mlx);
}

t_bressen	bressen_vars_init(t_node node1, t_node node2)
{
	t_bressen	vars;

	vars.dx = ft_abs(node1.x - node2.x);
	vars.dy = ft_abs(node1.y - node2.y);
	vars.err_x = 0;
	vars.err_y = 0;
	vars.sx = get_direction(node1.x, node2.x);
	vars.sy = get_direction(node1.y, node2.y);
	vars.x = node1.x;
	vars.y = node1.y;
	vars.color = node1.color;
	return (vars);
}
