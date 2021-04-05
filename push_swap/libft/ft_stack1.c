/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:19:01 by tcider            #+#    #+#             */
/*   Updated: 2021/03/28 11:51:03 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_ilist		*ft_ilist_create(int value)
{
	t_ilist		*ilist;

	if (!(ilist = (t_ilist*)malloc(sizeof(t_ilist))))
		return (NULL);
	ilist->value = value;
	ilist->index = -1;
	ilist->tmp = -1;
	ilist->flag = 0;
	ilist->next = NULL;
	return (ilist);
}

t_stack				*ft_stack_create(void)
{
	t_stack		*stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
	return (stack);
}

void				ft_stack_push(t_stack *stack, int value, int *error)
{
	t_ilist		*ilist;

	*error = 0;
	if (!stack)
		*error = 1;
	if (!(ilist = ft_ilist_create(value)))
		*error = 1;
	if (*error)
		return ;
	ilist->next = stack->head;
	stack->head = ilist;
	stack->size += 1;
	if (!stack->tail)
		stack->tail = ilist;
}

void				ft_stack_push_back(t_stack *stack, int value, int *error)
{
	t_ilist		*ilist;

	*error = 0;
	if (!stack)
		*error = 1;
	if (!(ilist = ft_ilist_create(value)))
		*error = 1;
	if (*error)
		return ;
	if (stack->tail)
		stack->tail->next = ilist;
	if (!stack->head)
		stack->head = ilist;
	stack->tail = ilist;
	stack->size += 1;
}

void				ft_stack_pushfull(t_stack *stack, t_ilist *list, int *error)
{
	t_ilist		*ilist;

	*error = 0;
	if (!stack)
		*error = 1;
	if (!(ilist = ft_ilist_create(list->value)))
		*error = 1;
	if (*error)
		return ;
	ilist->next = stack->head;
	ilist->index = list->index;
	stack->head = ilist;
	stack->size += 1;
	if (!stack->tail)
		stack->tail = ilist;
}
