/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:40:06 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 13:02:17 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_stack_issortedb(t_stack *stack, int size)
{
	t_ilist		*tmp;

	if (stack)
	{
		tmp = stack->head;
		if (!size || size > stack->size)
			size = stack->size;
		while (tmp && tmp->next && --size)
		{
			if (tmp->next->value > tmp->value)
				return (0);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

int			ft_stack_sort(t_stack *stack)
{
	t_ilist			*list;
	int				tmp;

	if (!stack || !stack->head)
		return (1);
	while (!ft_stack_issorted(stack))
	{
		list = stack->head;
		while (list && list->next)
		{
			if (list->next->value < list->value)
			{
				tmp = list->value;
				list->value = list->next->value;
				list->next->value = tmp;
			}
			list = list->next;
		}
	}
	return (0);
}

int			ft_stack_median(t_stack *stack, int size, int *err)
{
	t_stack			*tmp;
	t_ilist			*list;
	int				i;

	tmp = ft_stack_copy(stack, size);
	if (!tmp || ft_stack_sort(tmp))
	{
		*err = 1;
		if (tmp)
			free(tmp);
		return (0);
	}
	i = -1;
	list = tmp->head;
	if (!size)
		size = tmp->size;
	while (++i < size / 2)
		list = list->next;
	*err = 0;
	free(tmp);
	return (list->value);
}

int			*ft_stack_toarr(t_stack *stack)
{
	int				*arr;
	t_ilist			*tmp;
	int				i;

	if (!(arr = (int*)malloc(sizeof(int) * stack->size)))
		return (NULL);
	i = 0;
	tmp = stack->head;
	while (tmp)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

t_ilist		*ft_stack_findmintmp(t_stack *stack)
{
	t_ilist		*list;
	t_ilist		*reslist;
	int			min;
	int			flag;

	reslist = NULL;
	if (stack && stack->size)
	{
		flag = 1;
		list = stack->head;
		while (list)
		{
			if (flag && list->tmp >= 0 && (reslist = list))
			{
				min = list->tmp;
				flag = 0;
			}
			else if (list->tmp >= 0 && list->tmp < min && (reslist = list))
				min = list->tmp;
			list = list->next;
		}
	}
	return (reslist);
}
