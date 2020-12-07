/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:05:46 by tcider            #+#    #+#             */
/*   Updated: 2020/11/07 12:25:13 by tcider           ###   ########.fr       */
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

t_headlst	*to_lst_makebuf(char *str, int size)
{
	t_headlst	*head;

	if (!(head = (t_headlst*)malloc(sizeof(t_headlst))))
		return (NULL);
	head->head = NULL;
	head->tail = NULL;
	head->size = 0;
	if (str)
	{
		head->head = to_create_elem(str, size);
		head->tail = head->head;
		head->size = head->head->size;
	}
	return (head);
}

t_headlst	*to_lst_addbuf(t_headlst *head, char *str, int size)
{
	t_lst		*elem;

	if (!head)
		head = to_lst_makebuf(str, size);
	else
	{
		if (!(elem = to_create_elem(str, size)))
			return (NULL);
		if (!(head->head))
			head->head = elem;
		if (head->tail)
			head->tail->next = elem;
		head->tail = elem;
		head->size += size;
	}
	return (head);
}

char		*to_lst_joinbuf(t_headlst *head)
{
	char		*res;
	t_lst		*tmp;
	int			i;
	int			k;

	if (!head || !head->head ||
		!(res = (char*)malloc(sizeof(char) * (head->size + 1))))
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

void		to_lst_clear(t_headlst *head)
{
	t_lst		*tmp;
	t_lst		*tmp2;

	if (!head)
		return ;
	if (head->head)
	{
		tmp = head->head;
		while (tmp)
		{
			if (tmp->data)
				free(tmp->data);
			tmp2 = tmp->next;
			free (tmp);
			tmp = tmp2;
		}
	}
	free (head);
}
