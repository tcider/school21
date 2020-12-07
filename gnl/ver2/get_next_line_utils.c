/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:05:46 by tcider            #+#    #+#             */
/*   Updated: 2020/11/06 20:02:14 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_new_line(char *str, int ret)
{
	int		i;

	i = -1;
	while (++i < ret)
		if (str[i] == '\n')
			return (i);
	return (-1);
}

void	free_list_line(t_buf **blst)
{
	free((*blst)->data);
	free(*blst);
	*blst = NULL;
}

void	split_nl_line(t_buf *blst, char *s1, char *s2)
{
	int		i;

	i = -1;
	while (++i < blst->size)
	{
		if (i < blst->nl)
			s1[i] = (blst->data)[i];
		else if (i == blst->nl)
			s1[i] = '\0';
		else if (s2 && i > blst->nl)
			s2[i - blst->nl - 1] = (blst->data)[i];
	}
}

int		split_buf_line(t_buf **blst, char **line)
{
	char	*tmp;
	int		size;
	
	tmp = NULL;
	size = (*blst)->size - (*blst)->nl - 1;
	if (!(*line = (char*)malloc(sizeof(char) * ((*blst)->nl + 1))) ||
		(size && !(tmp = (char*)malloc(sizeof(char) * size))))
	{
		free_list_line(blst);
		return (-1);
	}
	split_nl_line(*blst, *line, tmp);
	if (size)
	{
		(*blst)->size = size;
		(*blst)->nl = find_new_line(tmp, size);
		free((*blst)->data);
		(*blst)->data = tmp;
	}
	else
		free_list_line(blst);
	return (1);
}

int		add_buf_line(t_buf **blst, char *buf, int ret)
{
	int		size;
	int		i;
	char	*res;

	if (*blst)
		size = (*blst)->size;
	if (!(*blst) && (size = 0) && !(*blst = (t_buf*)malloc(sizeof(t_buf))))
		return (-1);
	if (!(res = (char*)malloc(sizeof(char) * (size + ret))))
		return (-1);
	i = -1;
	while (++i < size + ret)
		if (i < size)
			res[i] = ((*blst)->data)[i];
		else
			res[i] = buf[i - size];
	(*blst)->nl = find_new_line(buf, ret);
	if ((*blst)->nl != -1)
		(*blst)->nl += size;
	(*blst)->size = size + ret;
	if (size)
		free((*blst)->data);
	(*blst)->data = res;
	return ((*blst)->nl + 1);
}
