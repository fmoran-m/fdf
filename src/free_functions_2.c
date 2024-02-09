/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:10 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 22:23:08 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	exit_free_matmaptrans(t_map *map, t_node **matrix, t_trans *trans)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	free(map);
	free(trans);
	ft_putendl_fd(MEM_ERR, 2);
	exit (-1);
}

void	exit_all(t_map *map, t_node **matrix, t_trans *trans, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	free(map);
	free(trans);
	free(mlx);
	ft_putendl_fd(MEM_ERR, 2);
	exit (-1);
}

void	free_all(t_map *map, t_node **matrix, t_trans *trans, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	free(map);
	free(trans);
	free(mlx);
}
