/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:43:09 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/12/12 21:26:53 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexatoi(const char *str)
{
	int	acum;
	int	i;
	int	flag;

	acum = 0;
	i = 0;
	flag = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag = 1;
		i++;
	}
	if (str[i] == '0' && str[i + 1] == 'x')
			i = i + 2;
	while (str[i] >= '0' && str[i] <= '9' && str[i] >= 'a' && str[i] <= 'f' && str[i] <= 'A' && str[i] >= 'F')
	{
		if (str[i] >= '0' && str[i] <= '9')
			acum = acum * 10 + (str[i] - 48);
		else if (str[i] >= 'a' && str[i] <= 'f')
			acum = acum * 16 + (str[i] - 48);
		else if (str[i] >= 'A' && str[i] <= 'F')
			acum = acum * 16 + (str[i] - 48);
	}
	if (flag == 1)
		acum = acum * -1;
	return (acum);
}

int main (void)
{
	char *str;

	str = "0x123";
	ft_printf("%d\n", ft_hexatoi(str));
	return 0;
}
