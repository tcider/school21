/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:42:16 by tcider            #+#    #+#             */
/*   Updated: 2020/12/29 19:21:57 by tcider           ###   ########.fr       */
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
