/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:16 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 22:23:15 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(char **matrix, int y_counter)
{
	int	i;

	i = 0;
	while (i < y_counter)
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}