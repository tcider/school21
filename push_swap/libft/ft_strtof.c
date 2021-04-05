/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 21:15:29 by tcider            #+#    #+#             */
/*   Updated: 2020/12/14 10:33:46 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_strtof(char *str, char **tmp)
{
	int			i;
	int			sign;
	double		res;
	double		exp;

	i = 0;
	sign = 1;
	res = 0;
	exp = 0.1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || (str[i] == '-' && (sign = -1)))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (str[i] == '.' && ++i)
		while (str[i] >= '0' && str[i] <= '9')
		{
			res += (str[i++] - '0') * exp;
			exp *= 0.1;
		}
	*tmp = &str[i];
	return (sign * res);
}
