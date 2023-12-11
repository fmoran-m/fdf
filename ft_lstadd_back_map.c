/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:43:54 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/12/11 21:09:36 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lstadd_back_map(t_map **lst, t_map **head, t_map *new)
{
	t_map	*temp;

	if (!new)
		return ;
	temp = *lst;
	if (temp == NULL)
		temp = new;
	if (*head == NULL)
		*head = new;
	else
	{
		temp->next = new;
		temp = new;
	}
}
