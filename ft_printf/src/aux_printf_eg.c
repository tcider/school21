/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_printf_eg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:24:54 by tcider            #+#    #+#             */
/*   Updated: 2020/12/03 12:17:50 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <math.h>

static char		*aux_etext(char **res, int size, t_params *prms)
{
	char			*tmp;
	char			*tmp_res;
	int				sz_sign;

	sz_sign = 1;
	ft_straddc(res, prms->type);
	if (size < 0 && (sz_sign = -1))
		ft_straddc(res, '-');
	else
		ft_straddc(res, '+');
	if (sz_sign * size < 10)
		ft_straddc(res, '0');
	tmp = ft_itoa(sz_sign * size);
	tmp_res = *res;
	*res = ft_strjoin(tmp_res, tmp);
	free(tmp_res);
	if (tmp)
		free(tmp);
	prms->size = ft_strlen(*res) + ((prms->prefix) ? 1 : 0);
	while (!prms->align && prms->zero && prms->width > prms->size &&
		(prms->size += 1))
		ft_caddstr('0', res);
	if (prms->prefix)
		ft_caddstr(prms->prefix, res);
	return (*res);
}

char			*aux_print_e(va_list *ar_list, t_params *prms)
{
	char			*res;
	double			num;
	int				size;

	if (prms->lh)
		prms->ub = 1;
	if (prms->prec < 0)
		prms->prec = 6;
	size = 0;
	num = va_arg(*ar_list, double);
	if (num == INFINITY || num == -INFINITY || num != num)
		return (aux_infnan(num, prms));
	if (num < 0 && (prms->prefix = '-'))
		num = -num;
	while (num > 9 && (num /= 10))
		size++;
	while (num < 1 && (num *= 10))
		size--;
	res = aux_float(num, prms->prec);
	return (aux_etext(&res, size, prms));
}

static char		*aux_getext(double num, int size, t_params *prms)
{
	int				len;
	char			*res;

	if (prms->prec)
		prms->prec -= 1;
	res = aux_float(num, prms->prec);
	len = ft_strlen(res);
	while (--len && res[len] == '0')
		ft_strdelc(&res);
	if (res[len] == '.')
		ft_strdelc(&res);
	return (aux_etext(&res, size, prms));
}

static char		*aux_gftext(double num, int size, t_params *prms)
{
	int				len;
	char			*res;

	prms->prec = (size < 0) ? prms->prec - 1 - size : prms->prec - (size + 1);
	if (prms->prec < 0)
		prms->prec = 0;
	if (num > LLONG_MAX)
		res = aux_oversize(num, prms->prec);
	else
		res = aux_float(num, prms->prec);
	len = ft_strlen(res);
	while (prms->prec && --len && res[len] == '0')
		ft_strdelc(&res);
	if (res[len] == '.')
		ft_strdelc(&res);
	prms->size = ft_strlen(res) + ((prms->prefix) ? 1 : 0);
	while (!prms->align && prms->zero && prms->width > prms->size &&
		(prms->size += 1))
		ft_caddstr('0', &res);
	if (prms->prefix)
		ft_caddstr(prms->prefix, &res);
	return (res);
}

char			*aux_print_g(va_list *ar_list, t_params *prms)
{
	double			num;
	int				size;
	double			tmp;

	if (prms->lh)
		prms->ub = 1;
	if (prms->prec < 0)
		prms->prec = 6;
	size = 0;
	num = va_arg(*ar_list, double);
	if (num == INFINITY || num == -INFINITY || num != num)
		return (aux_infnan(num, prms));
	if (num < 0 && (prms->prefix = '-'))
		num = -num;
	tmp = num;
	while (num > 9 && (num /= 10))
		size++;
	while (num < 1 && (num *= 10))
		size--;
	if (size && (size > prms->prec - 1 || size < -4) && (prms->type -= 2))
		return (aux_getext(num, size, prms));
	else
		return (aux_gftext(tmp, size, prms));
}
