/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_printf_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:34:22 by tcider            #+#    #+#             */
/*   Updated: 2020/12/03 11:40:01 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

static char		*aux_wchar_string(wchar_t *wres, t_params *prms)
{
	int			i;
	int			tmp_size;
	char		*tmp;
	char		*res;
	char		*tmp_res;

	i = -1;
	res = NULL;
	while (wres[++i])
	{
		tmp = ft_strwchar(wres[i], &tmp_size);
		prms->size += tmp_size;
		if (!res)
			res = tmp;
		else
		{
			tmp_res = res;
			res = ft_strjoin(tmp_res, tmp);
			if (tmp)
				free(tmp);
			free(tmp_res);
		}
	}
	return (res);
}

char			*aux_print_string(va_list *ar_list, t_params *prms)
{
	char		*res;
	wchar_t		*wres;

	res = NULL;
	if (prms->prefix || prms->zero || (prms->lh && prms->lh != 1))
		prms->ub = 1;
	if (prms->lh == 1)
	{
		if ((wres = va_arg(*ar_list, wchar_t *)))
			return (aux_wchar_string(wres, prms));
		else
			res = ft_strdup("(null)");
	}
	else if (!(res = va_arg(*ar_list, char *)))
		res = ft_strdup("(null)");
	prms->size = ft_strlen(res);
	if (prms->prec >= 0 && prms->prec < prms->size)
		prms->size = prms->prec;
	res = ft_substr(res, 0, prms->size);
	while (!prms->align && prms->zero && prms->width > prms->size &&
		(prms->size += 1))
		ft_caddstr('0', &res);
	return (res);
}

char			*aux_print_char(va_list *ar_list, t_params *prms)
{
	int			c;
	char		*res;

	if (prms->prefix || prms->zero || prms->prec != -1 ||
		(prms->lh && prms->lh != 1))
		prms->ub = 1;
	c = va_arg(*ar_list, int);
	if (prms->lh == 1)
		res = ft_strwchar(c, &(prms->size));
	else
	{
		res = NULL;
		prms->size = 1;
		ft_caddstr((char)c, &res);
	}
	while (!prms->align && prms->zero && prms->width > prms->size &&
		(prms->size += 1))
		ft_caddstr('0', &res);
	return (res);
}

char			*aux_print_prs(t_params *prms)
{
	char			*res;

	prms->size = 1;
	res = NULL;
	ft_caddstr('%', &res);
	while (!prms->align && prms->zero && prms->width > prms->size &&
		(prms->size += 1))
		ft_caddstr('0', &res);
	return (res);
}
