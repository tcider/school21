/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minignl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:42:05 by tcider            #+#    #+#             */
/*   Updated: 2021/03/16 14:42:07 by tcider           ###   ########.fr       */
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

int				ft_minignl(int fd, char **line)
{
	int		a;
	char	c;
	int		flag;
	char	*buf;

	flag = 1;
	buf = NULL;
	while (flag && (a = read(fd, &c, 1)) == 1)
		if (c != '\n')
			ft_straddc(&buf, c);
		else
			flag = 0;
	if (!buf)
		buf_init(&buf);
	*line = buf;
	return (a);
}
