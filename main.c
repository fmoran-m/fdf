/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:16:45 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 20:58:18 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_mlx		*mlx;
	t_node		**matrix;
	t_trans		*trans;

	if (argc != 2)
		exit_program(ARG_ERR);
	file_checker(argv[1]);
	map = map_init();
	map->height = rows_counter(argv[1], map); 
	matrix = (t_node **)ft_calloc(map->height + 1, sizeof(t_node *));
	if (!matrix)
		exit_free_map(MEM_ERR, map);
	matrix = read_map(argv[1], matrix, map);
	trans = trans_init(matrix, map); 
	mlx = graphic_init(matrix, map, trans);
	draw_map(matrix, map, mlx, trans);
	esc_inputs(mlx);
	mlx_loop(mlx->mlx);
	free_all(map, matrix, trans, mlx);
	return (0);
}
