/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:40:56 by tcider            #+#    #+#             */
/*   Updated: 2020/11/12 10:17:32 by tcider           ###   ########.fr       */
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
	while (++i < ret)
		if (str[i] == '\n')
			return (i);
	return (-1);
}

static int		free_buf(t_buf **buf)
{
	if (*buf)
	{
		if ((*buf)->data)
			free((*buf)->data);
		free(*buf);
		*buf = NULL;
	}
	return (1);
}

static int		read_file(int fd, char **line, t_headlst **buf_lst, t_buf **fdb)
{
	int				ret;
	char			*buf;
	int				nl;

	nl = -1;
	ret = 1;
	while (nl == -1 && (buf = (char*)malloc(sizeof(char) * BUFFER_SIZE)) &&
		(ret = read(fd, buf, BUFFER_SIZE)) > 0)
		if ((nl = find_new_line(buf, ret)) != -1)
			*buf_lst = to_lst_addbuf(*buf_lst, buf, nl);
		else
			*buf_lst = to_lst_addbuf(*buf_lst, buf, ret);
	if (ret <= 0)
		free(buf);
	else if (!buf || !*buf_lst)
		ret = -1;
	if ((nl != -1 && ret != -1) || ret == 0)
		if (!(*line = to_lst_joinbuf(*buf_lst)))
			ret = -1;
	if (ret != -1 && nl != -1 && ((*fdb)->size = ret - nl - 1) > 0)
		(*fdb)->data = get_substr(buf, nl + 1, ret - nl - 1);
	to_lst_clear(buf_lst, fdb, ret);
	if (ret > 0)
		ret = 1;
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static t_buf	*fd_buf;
	t_headlst		*buf_list;
	int				nl;
	char			*tmp;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (fd_buf && fd_buf->data &&
		(nl = find_new_line(fd_buf->data, fd_buf->size)) != -1)
	{
		if (!(*line = get_substr(fd_buf->data, 0, nl)) &&
			free_buf(&fd_buf))
			return (-1);
		tmp = get_substr(fd_buf->data, nl + 1, fd_buf->size - nl - 1);
		free(fd_buf->data);
		fd_buf->data = tmp;
		fd_buf->size = fd_buf->size - nl - 1;
		if (!tmp)
			free_buf(&fd_buf);
		return (1);
	}
	if (!(buf_list = to_lst_makebuf(&fd_buf)) && free_buf(&fd_buf))
		return (-1);
	return (read_file(fd, line, &buf_list, &fd_buf));
}
