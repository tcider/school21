/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:05:46 by tcider            #+#    #+#             */
/*   Updated: 2020/11/07 19:28:53 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst		*to_create_elem(char *str, int size)
{
	t_lst		*elem;

	if (!str)
		return (NULL);
	if (size == -1 && !(size = 0))
		while (str[size])
			size++;
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
		head->head = to_create_elem((*buf)->data, (*buf)->size);
		head->tail = head->head;
		head->size = head->head->size;
	}
	else
	{
		if (!(*buf = (t_buf*)malloc(sizeof(t_buf))))
			return (NULL);
		(*buf)->data = NULL;
	}
	return (head);
}

t_headlst	*to_lst_addbuf(t_headlst *head, char *str, int size)
{
	t_lst		*elem;

	if (!(elem = to_create_elem(str, size)))
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
		//printf("join - '%s' - %d\n", tmp->data, tmp->size);
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
			free (tmp);
			tmp = tmp2;
		}
		free (*head);
	}
	if (ret == -1 || (*buf && (!((*buf)->data) || !((*buf)->size))))
	{
		if (*buf)
			free(*buf);
		*buf = NULL;
	}
}
