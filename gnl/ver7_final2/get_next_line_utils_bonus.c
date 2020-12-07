/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:05:20 by tcider            #+#    #+#             */
/*   Updated: 2020/11/11 20:05:28 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_lst		*to_create_elem(char *str, int size)
{
	t_lst		*elem;

	if (!str)
		return (NULL);
	if (!(elem = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	elem->data = str;
	elem->next = NULL;
	elem->size = size;
	return (elem);
}

t_headlst	*to_lst_makebuf(t_buf **buf)
{
	t_headlst	*head;

	if (!(head = (t_headlst*)malloc(sizeof(t_headlst))))
		return (NULL);
	head->head = NULL;
	head->tail = NULL;
	head->size = 0;
	if (*buf && (*buf)->data && (*buf)->size)
	{
		if (!(head->head = to_create_elem((*buf)->data, (*buf)->size)))
			return (NULL);
		head->tail = head->head;
		head->size = head->head->size;
	}
	else if (!*buf)
		if (!(*buf = (t_buf*)malloc(sizeof(t_buf))))
			return (NULL);
	(*buf)->data = NULL;
	return (head);
}

t_headlst	*to_lst_addbuf(t_headlst *head, char *str, int size)
{
	t_lst		*elem;

	if (!head || !(elem = to_create_elem(str, size)))
		return (NULL);
	if (!(head->head))
		head->head = elem;
	if (head->tail)
		head->tail->next = elem;
	head->tail = elem;
	head->size += size;
	return (head);
}

char		*to_lst_joinbuf(t_headlst *head)
{
	char		*res;
	t_lst		*tmp;
	int			i;
	int			k;

	if (!(res = (char*)malloc(sizeof(char) * (head->size + 1))))
		return (NULL);
	k = -1;
	tmp = head->head;
	while (tmp)
	{
		i = -1;
		while (++i < tmp->size)
			res[++k] = (tmp->data)[i];
		tmp = tmp->next;
	}
	res[++k] = '\0';
	return (res);
}

void		to_lst_clear(t_headlst **head, t_buf **buf, int ret)
{
	t_lst		*tmp;
	t_lst		*tmp2;

	if (*head)
	{
		tmp = (*head)->head;
		while (tmp)
		{
			if (tmp->data)
				free(tmp->data);
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
		}
		free(*head);
		*head = NULL;
	}
	if (ret == -1 || (*buf && !((*buf)->data)))
	{
		if ((*buf)->data)
			free((*buf)->data);
		if (*buf)
			free(*buf);
		*buf = NULL;
	}
}
