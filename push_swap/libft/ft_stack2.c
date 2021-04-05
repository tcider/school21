/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:40:06 by tcider            #+#    #+#             */
/*   Updated: 2021/03/25 11:48:54 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_stack_posbyval(t_stack *stack, int value)
{
	t_ilist		*tmp;
	int			i;

	if (stack)
	{
		i = 1;
		tmp = stack->head;
		while (tmp)
		{
			if (tmp->value == value)
				return (i);
			i++;
			tmp = tmp->next;
		}
	}
	return (0);
}

int			ft_stack_issorted(t_stack *stack)
{
	t_ilist		*tmp;

	if (stack)
	{
		tmp = stack->head;
		while (tmp && tmp->next)
		{
			if (tmp->next->value < tmp->value)
				return (0);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

int			ft_stack_free(t_stack **stack)
{
	t_ilist		*tmp;
	t_ilist		*tmp_next;

	if (*stack)
	{
		tmp = (*stack)->head;
		while (tmp)
		{
			tmp_next = tmp->next;
			free(tmp);
			tmp = tmp_next;
		}
		free(*stack);
		*stack = NULL;
	}
	return (1);
}

void		ft_stack_swap(t_stack *stack)
{
	t_ilist		*tmp;

	if (stack->size == 2)
	{
		stack->head->next = NULL;
		stack->tail->next = stack->head;
		stack->head = stack->tail;
		stack->tail = stack->head->next;
	}
	if (stack->size > 2)
	{
		tmp = stack->head;
		stack->head = tmp->next;
		tmp->next = stack->head->next;
		stack->head->next = tmp;
	}
}

void		ft_stack_rotate(t_stack *stack, int direction)
{
	t_ilist		*tmp;

	if (stack && stack->size > 1)
	{
		if (direction == 1)
		{
			tmp = stack->head;
			stack->head = tmp->next;
			stack->tail->next = tmp;
			tmp->next = NULL;
			stack->tail = tmp;
		}
		if (direction == -1)
		{
			tmp = stack->head;
			while (tmp->next->next)
				tmp = tmp->next;
			stack->tail->next = stack->head;
			stack->tail = tmp;
			stack->head = stack->tail->next;
			stack->tail->next = NULL;
		}
	}
}
