/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:46:34 by tcider            #+#    #+#             */
/*   Updated: 2020/12/04 18:53:22 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define CONVERSIONS "cspdiuxX%nfFgGeE"
# define FLAGS "-+ #0"

typedef struct	s_params
{
	int			i;
	char		align;
	char		prefix;
	char		octotorp;
	char		zero;
	int			width;
	int			prec;
	char		lh;
	char		type;
	int			size;
	char		ub;
}				t_params;

int				ft_printf(const char *str, ...);
void			aux_printf(va_list *ar_list, t_params *params);
char			*aux_print_n(va_list *ar_list, t_params *prms);
char			*aux_print_num(va_list *ar_list, t_params *prms);
char			*aux_print_unum(va_list *ar_list, t_params *prms);
char			*aux_print_hex(va_list *ar_list, t_params *prms);
char			*aux_print_ptr(va_list *ar_list, t_params *prms);
char			*aux_print_string(va_list *ar_list, t_params *prms);
char			*aux_print_char(va_list *ar_list, t_params *prms);
char			*aux_print_prs(t_params *prms);
char			*aux_oversize(double unum, int prec);
char			*aux_float(double unum, int prec);
char			*aux_infnan(double num, t_params *prms);
char			*aux_print_f(va_list *ar_list, t_params *prms);
char			*aux_print_e(va_list *ar_list, t_params *prms);
char			*aux_print_g(va_list *ar_list, t_params *prms);

#endif
