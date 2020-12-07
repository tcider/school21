/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:40:56 by tcider            #+#    #+#             */
/*   Updated: 2020/11/06 20:02:17 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int fd, char **line)
{
	int				nl;
	int				ret;
	char			*buf;
	static t_buf	*fd_buf[FD_LIM + 1];

	if (!line || fd < 0)
		return (-1);
	if (fd_buf[fd] && (fd_buf[fd])->nl != -1)
			return (split_buf_line(&fd_buf[fd], line));
	while ((buf = (char*)malloc(sizeof(char) * BUF_SIZE)) &&
		(ret = read(fd, buf, BUF_SIZE)) > 0 &&
		!(nl = add_buf_line(&fd_buf[fd], buf, ret)))
		free(buf);
	if (nl > 0)
		return (split_buf_line(&fd_buf[fd], line));
	if ((ret == -1 || !buf || nl == -1) && (ret = -1))
		free_list_line(&fd_buf[fd]);
	if (!ret && !(*line = NULL) && fd_buf[fd] && (fd_buf[fd])->data)
		*line = (fd_buf[fd])->data;
	return (ret);
}
