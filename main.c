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

static int	render_frame(t_control *control)
{
	if (control->trans->z_rot_bool == 1)
		control->trans->z_rot += 0.05;
	if (control->trans->x_rot_bool == 1)
		control->trans->x_rot += 0.05;
	if (control->trans->y_rot_bool == 1)
		control->trans->y_rot += 0.05;
	draw_map(control->matrix, control->map, control->mlx, control->trans);
	return (0);
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
	matrix = read_map(argv[1], matrix, map);
	trans = trans_init(matrix, map); 
	mlx = graphic_init(matrix, map, trans);
	draw_map(matrix, map, mlx, trans);
	control = control_init(map, mlx, matrix, trans); //Hacer exit dentro
	inputs(control);
	mlx_loop_hook(mlx->mlx, render_frame, control);
	mlx_loop(mlx->mlx);
	free_all(map, matrix, trans, mlx);
	free(control);
	return (0);
}
