/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:39 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/01 22:24:23 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char const *s, unsigned char c)
{
	int	flag;
	int	i;
	int	n;

	flag = 1;
	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 1 && s[i] != '\n')
		{
			n++;
			flag = 0;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (n);
}

int	isxdigit_fdf(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'f')
		return (1);
	else if (c >= 'A' && c <= 'F')
		return (1);
	else if (c == 'x' || c == 'X')
		return (1);
	else if (c == ',')
		return (1);
	else if (c == '-')
		return (1);
	else if (c == '\n')
		return (1);
	else
		return (0);
}

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	get_direction(int num1, int num2)
{
	int	s;

	s = 0;
	if (num1 < num2)
		s = 1;
	else
		s = -1;
	return (s);
}
