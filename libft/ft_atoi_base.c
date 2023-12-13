/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:43:09 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/12/13 18:29:56 by fmoran-m         ###   ########.fr       */

/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int ft_atoi_base(const char *str) {
    if (str == NULL || str[0] == '\0') {
        return 0;
    }
    int result = 0;
    int i = 0;
    while (isspace(str[i])) {
        i++;
    }
    if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')) {
        i += 2;
    }
    while (isxdigit(str[i])) {
        char digit = str[i];
        if (isdigit(digit)) {
            result = result * 16 + (digit - '0');
        } else {
            result = result * 16 + (toupper(digit) - 'A' + 10);
        }
        i++;
    }
    return result;
}
