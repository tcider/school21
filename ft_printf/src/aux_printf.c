/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:12:02 by tcider            #+#    #+#             */
/*   Updated: 2020/12/03 13:12:55 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*aux_print_unum(va_list *ar_list, t_params *prms)
{
	char		*res;

	if (prms->prefix)
		prms->ub = 1;
	res = NULL;
	if (prms->lh == -2)
		res = ft_ulitoa((unsigned char)va_arg(*ar_list, unsigned int));
	else if (prms->lh == -1)
		res = ft_ulitoa((unsigned short)va_arg(*ar_list, unsigned int));
	else if (prms->lh == 1)
		res = ft_ulitoa(va_arg(*ar_list, unsigned long));
	else if (prms->lh == 2)
		res = ft_ulitoa(va_arg(*ar_list, unsigned long long));
	else
		res = ft_ulitoa(va_arg(*ar_list, unsigned int));
	if (!prms->prec && *res == '0')
		ft_strdelc(&res);
	prms->size = ft_strlen(res);
	while (((!prms->align && prms->zero && prms->width > prms->size) ||
		prms->prec > prms->size) && (prms->size += 1))
		ft_caddstr('0', &res);
	return (res);
}

char			*aux_print_num(va_list *ar_list, t_params *prms)
{
	char		*res;

	if (prms->lh == -2)
		res = ft_itoa((char)va_arg(*ar_list, int));
	else if (prms->lh == -1)
		res = ft_itoa((short)va_arg(*ar_list, int));
	else if (prms->lh == 1)
		res = ft_litoa(va_arg(*ar_list, long));
	else if (prms->lh == 2)
		res = ft_litoa(va_arg(*ar_list, long long));
	else
		res = ft_itoa(va_arg(*ar_list, int));
	if (!prms->prec && *res == '0')
		ft_strdelc(&res);
	prms->size = ft_strlen(res);
	if (*res == '-' && (prms->prefix = '-') && prms->size--)
		ft_cdelstr(&res);
	while (((!prms->align && prms->zero && prms->width > prms->size +
		(prms->prefix ? 1 : 0)) || prms->prec > prms->size) && (prms->size++))
		ft_caddstr('0', &res);
	if (prms->prefix && (prms->size += 1))
		ft_caddstr(prms->prefix, &res);
	return (res);
}

char			*aux_print_n(va_list *ar_list, t_params *prms)
{
	char		*tmp_char;
	short		*tmp_short;
	long		*tmp_long;
	long long	*tmp_ll;
	int			*tmp_int;

	if (prms->lh == -2 && (tmp_char = va_arg(*ar_list, char*)))
		*tmp_char = (char)(prms->i);
	else if (prms->lh == -1 && (tmp_short = va_arg(*ar_list, short*)))
		*tmp_short = (short)(prms->i);
	else if (prms->lh == 1 && (tmp_long = va_arg(*ar_list, long*)))
		*tmp_long = (long)(prms->i);
	else if (prms->lh == 2 && (tmp_ll = va_arg(*ar_list, long long*)))
		*tmp_ll = (long long)(prms->i);
	else
	{
		tmp_int = va_arg(*ar_list, int*);
		*tmp_int = prms->i;
	}
	prms->size = 0;
	return (NULL);
}

/*
** aux_raw_outpaut returns string of raw argument without formatting
** it includes sign even space if space flag
** it provides eroors of children functions
*/

static char		*aux_raw_output(va_list *ar_list, t_params *params)
{
	if (params->type == 'd' || params->type == 'i')
		return (aux_print_num(ar_list, params));
	else if (params->type == 'u')
		return (aux_print_unum(ar_list, params));
	else if (params->type == 'n')
		return (aux_print_n(ar_list, params));
	else if (params->type == 'x' || params->type == 'X')
		return (aux_print_hex(ar_list, params));
	else if (params->type == 'p')
		return (aux_print_ptr(ar_list, params));
	else if (params->type == 's')
		return (aux_print_string(ar_list, params));
	else if (params->type == 'c')
		return (aux_print_char(ar_list, params));
	else if (params->type == 'f' || params->type == 'F')
		return (aux_print_f(ar_list, params));
	else if (params->type == 'e' || params->type == 'E')
		return (aux_print_e(ar_list, params));
	else if (params->type == 'g' || params->type == 'G')
		return (aux_print_g(ar_list, params));
	else if (params->type == '%')
		return (aux_print_prs(params));
	return (NULL);
}

/*
** aux_printf has got params for one argument to print
** if formats only spaces width and align
*/

void			aux_printf(va_list *ar_list, t_params *prms)
{
	char		*res;

	if (prms->prec >= 0 && prms->zero && ft_strchr("diuxX", prms->type))
		prms->zero = 0;
	if (prms->width < 0 && (prms->width = -prms->width))
		prms->align = 1;
	if (!(res = aux_raw_output(ar_list, prms)))
		return ;
	if (prms->width <= prms->size || prms->type == 'n')
		ft_putnstr(res, prms->size);
	else
	{
		if (prms->align)
		{
			ft_putnstr(res, prms->size);
			ft_putnchar(' ', prms->width - prms->size);
		}
		else
		{
			ft_putnchar(' ', prms->width - prms->size);
			ft_putnstr(res, prms->size);
		}
		prms->size = prms->width;
	}
	free(res);
}
