/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:16:47 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 18:17:18 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	file_checker(char *argv)
{
	char	*fdf;
	char	*file_type;

	fdf = ".fdf";
	file_type = ft_strrchr(argv, '.');
	if (!file_type || ft_strcmp(fdf, file_type) != 0)
		exit_program(FILE_ERR);
}