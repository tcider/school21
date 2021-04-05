/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:34:54 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 12:47:38 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_heapstr		*ft_heapstr_create(void)
{
	t_heapstr	*heapstr;

	if (!(heapstr = (t_heapstr*)malloc(sizeof(t_heapstr))) || \
		!(heapstr->str = (char*)malloc(sizeof(char) * (HSTR_SIZE + 1))))
		return (NULL);
	heapstr->size = 0;
	return (heapstr);
}

void			ft_heapstr_free(t_heapstr **hstr)
{
	if (*hstr && (*hstr)->str)
	{
		free((*hstr)->str);
		free(*hstr);
	}
	*hstr = NULL;
}

int				ft_heapstr_add(t_heapstr *hstr, char c)
{
	char		*tmp;

	if (!hstr)
		return (1);
	if (hstr->size && hstr->size % HSTR_SIZE == 0)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (hstr->size + HSTR_SIZE + 1))))
			return (1);
		ft_strlcpy(tmp, hstr->str, hstr->size + 1);
		free(hstr->str);
		hstr->str = tmp;
	}
	(hstr->str)[hstr->size] = c;
	hstr->size += 1;
	(hstr->str)[hstr->size] = '\0';
	return (0);
}
