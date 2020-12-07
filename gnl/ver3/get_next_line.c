/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:40:56 by tcider            #+#    #+#             */
/*   Updated: 2020/11/07 12:32:27 by tcider           ###   ########.fr       */
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

static int		read_file(int fd, char **line, t_headlst *buf_lst, char **fd_sb)
{
	int				ret;
	char			*buf;
	int				nl_ind;

	nl_ind = -1;
	while (nl_ind == -1 &&
		(buf = (char*)malloc(sizeof(char) * BUFFER_SIZE)) &&
		(ret = read(fd, buf, BUFFER_SIZE)) > 0)
		if ((nl_ind = find_new_line(buf, ret)) != -1)
			buf_lst = to_lst_addbuf(buf_lst, buf, nl_ind);
		else
			buf_lst = to_lst_addbuf(buf_lst, buf, ret);
	if ((nl_ind != -1 || ret == 0) && buf_lst)
		*line = to_lst_joinbuf(buf_lst);
	if (nl_ind != -1 && nl_ind < ret - 1 && buf_lst)
		*fd_sb = get_substr(buf, nl_ind + 1, ret - nl_ind - 1);
	if (ret <= 0)
		free(buf);
	if (!buf || !buf_lst)
		ret = -1;
	to_lst_clear(buf_lst);
	if (ret > 0)
		ret = 1;
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static char		*fd_strings[FD_LIM + 1];
	t_headlst		*buf_list;
	int				nl;
	char			*tmp;

	//printf("static - '%s'\n", fd_strings[fd]);
	if (!line || fd < 0 || fd > FD_LIM)
		return (-1);
	if (fd_strings[fd] && (nl = find_new_line(fd_strings[fd], -1)) != -1)
	{
		*line = get_substr(fd_strings[fd], 0, nl);
		tmp = get_substr(fd_strings[fd], nl + 1, -1);
		free(fd_strings[fd]);
		fd_strings[fd] = tmp;
		if (!(*line))
			return (-1);
		return (1);
	}
	if (!(buf_list = to_lst_makebuf(fd_strings[fd], -1)))
		free(fd_strings[fd]);
	fd_strings[fd] = NULL;
	if (!buf_list)
		return (-1);
	return (read_file(fd, line, buf_list, &fd_strings[fd]));
}
