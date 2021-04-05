/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 21:11:08 by tcider            #+#    #+#             */
/*   Updated: 2020/12/14 10:33:34 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_strtoi(char *str, char **tmp)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((LONG_MAX / 10 - (str[i] - '0')) < res)
			return ((1 + sign) / (-2));
		res = res * 10 + str[i] - '0';
		i++;
	}
	*tmp = &str[i];
	return ((int)sign * res);
}
