/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_printf_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 11:08:33 by tcider            #+#    #+#             */
/*   Updated: 2020/12/03 11:46:22 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		aux_strhex(unsigned long long num, char **res, t_params *prms)
{
	int				ost;
	char			c;
	char			a_char;

	if (!*res)
		if (!(*res = (char*)malloc(sizeof(char))))
			*res = NULL;
	**res = '\0';
	a_char = (prms->type == 'x' || prms->type == 'X') ? prms->type - 23 : 'a';
	if (!num && prms->prec && (prms->size = 1))
		ft_caddstr('0', res);
	while (num)
	{
		ost = num % 16;
		if (ost > 9)
			c = a_char - 10 + ost;
		else
			c = '0' + ost;
		ft_caddstr(c, res);
		prms->size++;
		num = num / 16;
	}
}

char			*aux_print_hex(va_list *ar_list, t_params *prms)
{
	char			*res;

	if (prms->prefix)
		prms->ub = 1;
	res = NULL;
	if (prms->lh == -2)
		aux_strhex((unsigned char)va_arg(*ar_list, unsigned int), &res, prms);
	else if (prms->lh == -1)
		aux_strhex((unsigned short)va_arg(*ar_list, unsigned int), &res, prms);
	else if (prms->lh == 1)
		aux_strhex(va_arg(*ar_list, unsigned long), &res, prms);
	else if (prms->lh == 2)
		aux_strhex(va_arg(*ar_list, unsigned long long), &res, prms);
	else
		aux_strhex(va_arg(*ar_list, unsigned int), &res, prms);
	while (((!prms->align && prms->zero && prms->width > prms->size +
		(prms->octotorp ? 2 : 0)) || prms->prec > prms->size) && (prms->size++))
		ft_caddstr('0', &res);
	if (prms->octotorp && (prms->size += 2))
	{
		ft_caddstr(prms->type, &res);
		ft_caddstr('0', &res);
	}
	return (res);
}

char			*aux_print_ptr(va_list *ar_list, t_params *prms)
{
	char			*res;

	res = NULL;
	if (prms->prefix || prms->zero || prms->prec != -1 || prms->lh)
		prms->ub = 1;
	aux_strhex(va_arg(*ar_list, unsigned long), &res, prms);
	while (((!prms->align && prms->zero && prms->width > prms->size + 2) ||
		prms->prec > prms->size) && (prms->size += 1))
		ft_caddstr('0', &res);
	ft_caddstr('x', &res);
	ft_caddstr('0', &res);
	prms->size += 2;
	return (res);
}
