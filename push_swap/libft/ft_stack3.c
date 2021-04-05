/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:51:53 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 13:46:36 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_stack_print(t_stack *stack)
{
	t_ilist		*tmp;

	tmp = stack->head;
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		if ((tmp = tmp->next))
			write(1, ", ", 2);
	}
}

int			ft_stack_top(t_stack *stack, int *error)
{
	if (!stack || !stack->size)
	{
		*error = 1;
		return (0);
	}
	*error = 0;
	return (stack->head->value);
}

int			ft_stack_pretop(t_stack *stack, int *error)
{
	if (!stack || stack->size < 2)
	{
		*error = 1;
		return (0);
	}
	*error = 0;
	return (stack->head->next->value);
}

t_stack		*ft_stack_copy(t_stack *stack, int size)
{
	t_stack		*copy;
	t_ilist		*list;
	int			err;

	err = 0;
	if (!stack || !(copy = ft_stack_create()))
		return (NULL);
	list = stack->head;
	if (!size || size > stack->size)
		size = stack->size;
	while (list && size)
	{
		ft_stack_push_back(copy, list->value, &err);
		copy->tail->index = list->index;
		copy->tail->tmp = list->tmp;
		if (err && ft_stack_free(&copy))
			return (NULL);
		list = list->next;
		size -= 1;
	}
	return (copy);
}

t_ilist		*ft_stack_findbyind(t_stack *stack, int ind)
{
	t_ilist		*tmp;

	if (stack && stack->size)
	{
		tmp = stack->head;
		while (tmp)
		{
			if (tmp->index == ind)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (NULL);
}
