/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:07:49 by tcider            #+#    #+#             */
/*   Updated: 2020/12/29 19:22:56 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		buf_init(char **str)
{
	if (!*str)
	{
		if (!(*str = (char*)malloc(sizeof(char))))
		{
			*str = NULL;
			return ;
		}
		(*str)[0] = '\0';
	}
}

void			ft_straddc(char **str, char c)
{
	int			size;
	char		*tmp;
	int			i;

	if (!*str)
		buf_init(str);
	size = 0;
	tmp = *str;
	while (tmp[size])
		size++;
	if (!(*str = (char*)malloc(sizeof(char) * (size + 2))))
	{
		free(tmp);
		*str = NULL;
		return ;
	}
	i = -1;
	while (++i < size)
		(*str)[i] = tmp[i];
	(*str)[size] = c;
	(*str)[size + 1] = '\0';
	free(tmp);
}
