/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:17:46 by tcider            #+#    #+#             */
/*   Updated: 2021/04/02 10:48:56 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
** str should be null-terminated!
** in case of run out int size it returns some number and *tmp not null
*/

int		ft_strtoi_int(char *str, char **tmp)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	*tmp = &str[i];
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+') && ++i)
		if (str[i - 1] == '-')
			sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((sign == 1 && ((INT_MAX - (str[i] - '0')) / 10 < res)) || \
			(sign == -1 && ((INT_MAX - (str[i] - '0' - 1)) / 10 < res)))
			break ;
		res = res * 10 + str[i] - '0';
		i++;
		*tmp = &str[i];
	}
	return ((int)sign * res);
}
