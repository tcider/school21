/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_printf_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:07:38 by tcider            #+#    #+#             */
/*   Updated: 2020/12/03 12:19:41 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <math.h>

char			*aux_oversize(double unum, int prec)
{
	char			*res;

	res = ft_ulitoa(LLONG_MAX + 1);
	while (unum > LLONG_MAX)
	{
		ft_straddc(&res, '0');
		unum /= 10;
	}
	ft_straddc(&res, '.');
	while (prec--)
		ft_straddc(&res, '0');
	return (res);
}

static void		aux_round(char **res)
{
	int		size;
	int		flag;

	flag = 1;
	size = ft_strlen(*res);
	while (size-- && flag)
		if ((*res)[size] != '.')
		{
			if ((*res)[size] - '0' < 9)
			{
				(*res)[size] = (*res)[size] + 1;
				flag = 0;
			}
			else
			{
				(*res)[size] = '0';
				flag = 1;
			}
		}
	if (flag)
		ft_caddstr('1', res);
}

char			*aux_infnan(double num, t_params *prms)
{
	char			*res;

	res = NULL;
	if (num == INFINITY)
		res = ft_islcase(prms->type) ? ft_strdup("inf") : ft_strdup("INF");
	else if (num == -INFINITY)
		res = ft_islcase(prms->type) ? ft_strdup("-inf") : ft_strdup("-INF");
	else if (num != num)
		res = ft_islcase(prms->type) ? ft_strdup("nan") : ft_strdup("NAN");
	prms->size = ft_strlen(res);
	if (prms->zero)
		prms->zero = 0;
	return (res);
}

char			*aux_float(double unum, int prec)
{
	unsigned long	tmp;
	int				a;
	char			*res;

	tmp = (unsigned long)unum;
	res = ft_ulitoa(tmp);
	if (prec)
		ft_straddc(&res, '.');
	unum -= tmp;
	while (prec--)
	{
		unum *= 10;
		a = (int)unum;
		ft_straddc(&res, a + '0');
		unum -= a;
	}
	if ((int)(unum * 10) > 4)
		aux_round(&res);
	return (res);
}

char			*aux_print_f(va_list *ar_list, t_params *prms)
{
	char			*res;
	double			num;

	if (prms->lh)
		prms->ub = 1;
	if (prms->prec < 0)
		prms->prec = 6;
	num = va_arg(*ar_list, double);
	if (num == INFINITY || num == -INFINITY || num != num)
		return (aux_infnan(num, prms));
	if (num < 0 && (prms->prefix = '-'))
		num = -num;
	if (num > LLONG_MAX)
		res = aux_oversize(num, prms->prec);
	else
		res = aux_float(num, prms->prec);
	prms->size = ft_strlen(res) + ((prms->prefix) ? 1 : 0);
	while (!prms->align && prms->zero && prms->width > prms->size &&
		(prms->size += 1))
		ft_caddstr('0', &res);
	if (prms->prefix)
		ft_caddstr(prms->prefix, &res);
	return (res);
}
