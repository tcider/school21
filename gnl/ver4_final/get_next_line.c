/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:40:56 by tcider            #+#    #+#             */
/*   Updated: 2020/11/07 19:27:32 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*get_substr(char *s, int start, int len)
{
	char		*res;
	int			i;

	if (!s || !s[start])
		return (NULL);
	i = 0;
	if (len == -1 && !(len = 0))
		while(s[start + len])
			len++;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);

}

static	int		find_new_line(char *str, int ret)
{
	int		i;

	if (!str)
		return (-1);
	i = -1;
	if (ret == -1 && !(ret = 0))
		while (str[ret])
			ret++;
	while (++i < ret)
		if (str[i] == '\n')
			return (i);
	return (-1);
}

int				free_buf(t_buf *buf)
{
	if (buf)
	{
		if (buf->data)
			free(buf->data);
		free(buf);
	}
	return (1);
}

static int		read_file(int fd, char **line, t_headlst *buf_lst, t_buf **fdb)
{
	int				ret;
	char			*buf;
	int				nl;

	nl = -1;
	while (nl == -1 &&
		(buf = (char*)malloc(sizeof(char) * BUFFER_SIZE)) &&
		(ret = read(fd, buf, BUFFER_SIZE)) > 0)
		if ((nl = find_new_line(buf, ret)) != -1)
			buf_lst = to_lst_addbuf(buf_lst, buf, nl);
		else
			buf_lst = to_lst_addbuf(buf_lst, buf, ret);
	if (ret <= 0)
		free(buf);
	if (!buf && !buf_lst)
		ret = -1;
	if (nl != -1 || ret == 0)
		if (!(*line = to_lst_joinbuf(buf_lst)))
			ret = -1;
	if (nl != -1 && ((*fdb)->size = ret - nl - 1))
		(*fdb)->data = get_substr(buf, nl + 1, ret - nl - 1);
	to_lst_clear(&buf_lst, fdb, ret);
	if (ret > 0)
		ret = 1;
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static t_buf	*fd_buf[FD_LIM + 1];
	t_headlst		*buf_list;
	int				nl;
	char			*tmp;

	//if (fd_buf[fd])
	//	printf("static - '%s' - %d",
	//	fd_buf[fd]->data, fd_buf[fd]->size);
	if (!line || fd < 0 || fd > FD_LIM)
		return (-1);
	if (fd_buf[fd] && fd_buf[fd]->data &&
		(nl = find_new_line(fd_buf[fd]->data, fd_buf[fd]->size)) != -1)
	{
		if (!(*line = get_substr(fd_buf[fd]->data, 0, nl)) &&
			free_buf(fd_buf[fd]))
			return (-1);
		tmp = get_substr(fd_buf[fd]->data, nl + 1, fd_buf[fd]->size - nl - 1);
		free(fd_buf[fd]->data);
		fd_buf[fd]->data = tmp;
		fd_buf[fd]->size = fd_buf[fd]->size - nl - 1;
		if (!tmp && free_buf(fd_buf[fd]))
			fd_buf[fd] = NULL;
		return (1);
	}
	if (!(buf_list = to_lst_makebuf(&fd_buf[fd])) && free_buf(fd_buf[fd]))
		return (-1);
	return (read_file(fd, line, buf_list, &fd_buf[fd]));
}