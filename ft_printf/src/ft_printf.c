/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:43:36 by tcider            #+#    #+#             */
/*   Updated: 2020/12/03 13:39:08 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_zeroparams(t_params *params)
{
	params->align = 0;
	params->prefix = 0;
	params->octotorp = 0;
	params->zero = 0;
	params->width = 0;
	params->prec = -1;
	params->lh = 0;
	params->type = 0;
	params->size = 0;
	params->ub = 0;
}

static const char	*ft_parse_flags(const char *str, t_params *params)
{
	int				i;
	char			*tmp;

	i = -1;
	tmp = NULL;
	while (str[++i] && (tmp = ft_strchr(FLAGS, str[i])))
		if (*tmp == '-')
			params->align = 1;
		else if (*tmp == ' ' && !params->prefix)
			params->prefix = ' ';
		else if (*tmp == '+')
			params->prefix = '+';
		else if (*tmp == '#')
			params->octotorp = 1;
		else if (*tmp == '0')
			params->zero = 1;
	return (&str[i]);
}

/*
** ft_parse_type makes lh: 1 if "l", 2 if "ll", -1 if "h", -2 if "hh"
*/

static const char	*ft_parse_type(const char *str, t_params *params)
{
	int				i;
	char			*tmp;

	i = 0;
	tmp = NULL;
	if (str[i] && str[i] == 'l')
	{
		if (str[i + 1] && str[i + 1] == 'l' && (i += 2))
			params->lh = 2;
		else if ((i += 1))
			params->lh = 1;
	}
	else if (str[i] && str[i] == 'h')
	{
		if (str[i + 1] && str[i + 1] == 'h' && (i += 2))
			params->lh = -2;
		else if ((i += 1))
			params->lh = -1;
	}
	if (str[i] && (tmp = ft_strchr(CONVERSIONS, str[i])))
		params->type = *tmp;
	else
		i--;
	return (&str[i]);
}

/*
** ft_output returns size of conversion in string
** even if it is wrong conversion
*/

static int			ft_output(const char *str, va_list *ar_list, t_params *prms)
{
	const char		*tmp;
	int				i;

	i = 0;
	tmp = str;
	if ((str = ft_parse_flags(str, prms)) && str[i] && ft_isdigit(str[i]))
	{
		prms->width = ft_atoi(&str[i]);
		while (str[i] && (str[i] >= '0' && str[i] <= '9'))
			i += 1;
	}
	else if (str[i] && str[i] == '*' && (i += 1))
		prms->width = va_arg(*ar_list, int);
	if (str[i + 1] && str[i] == '.' && str[++i] == '*' && (i += 1))
		prms->prec = va_arg(*ar_list, int);
	else if (str[i] && str[i - 1] == '.')
	{
		prms->prec = ft_atoi(&str[i]);
		while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
			i += 1;
	}
	str = ft_parse_type(&str[i], prms);
	if (prms->type)
		aux_printf(ar_list, prms);
	return (str - tmp + 2);
}

/*
** ft_printf returns number of printed characters
** it returns all text form *str
** if conversion is wrong (undefined behavior for standart printf())
** it just skips wrong conversion and continues printing
*/

int					ft_printf(const char *str, ...)
{
	va_list			ar_list;
	int				cnv_size;
	int				prn_size;
	t_params		params;

	params.i = 0;
	cnv_size = 0;
	prn_size = 0;
	va_start(ar_list, str);
	while (str[params.i])
		if (str[params.i] == '%')
		{
			ft_zeroparams(&params);
			cnv_size = ft_output(&str[params.i + 1], &ar_list, &params);
			prn_size += params.size;
			params.i += cnv_size;
		}
		else if ((prn_size += 1))
			ft_putchar(str[params.i++]);
	va_end(ar_list);
	return (prn_size);
}
