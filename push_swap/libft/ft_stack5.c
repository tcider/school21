/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:40:06 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 13:47:06 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_stack_posbyind(t_stack *stack, int ind)
{
	t_ilist		*tmp;
	int			i;

	if (stack)
	{
		i = 1;
		tmp = stack->head;
		while (tmp)
		{
			if (tmp->index == ind)
				return (i);
			i++;
			tmp = tmp->next;
		}
	}
	return (0);
}

int			ft_stack_pop(t_stack *stack, int *error)
{
	int			res;
	t_ilist		*tmp;

	if (!stack || !stack->head)
		*error = 1;
	else
	{
		*error = 0;
		stack->size -= 1;
		res = stack->head->value;
		tmp = stack->head->next;
		free(stack->head);
		stack->head = tmp;
		if (!stack->size)
			stack->tail = NULL;
		return (res);
	}
	return (0);
}

void		ft_stack_printfull(t_stack *stack)
{
	t_ilist		*list;

	if (!stack || !stack->size)
		return ;
	list = stack->head;
	write(1, "===\n", 4);
	while (list)
	{
		ft_putnbr_fd(list->value, 1);
		write(1, " ind: ", 6);
		ft_putnbr_fd(list->index, 1);
		write(1, " tmp: ", 6);
		ft_putnbr_fd(list->tmp, 1);
		write(1, " flag: ", 7);
		ft_putnbr_fd(list->flag, 1);
		write(1, "\n", 1);
		list = list->next;
	}
	write(1, "===\n", 4);
}

int			ft_stack_posminval(t_stack *stack)
{
	t_ilist		*tmp;
	int			i;
	int			min;
	int			min_i;

	if (stack)
	{
		i = 1;
		min_i = 1;
		tmp = stack->head;
		min = tmp->value;
		while (tmp)
		{
			if (tmp->value < min)
			{
				min = tmp->value;
				min_i = i;
			}
			i++;
			tmp = tmp->next;
		}
		return (min_i);
	}
	return (0);
}

t_ilist		*ft_stack_findbyval(t_stack *stack, int value)
{
	t_ilist		*tmp;

	if (stack && stack->size)
	{
		tmp = stack->head;
		while (tmp)
		{
			if (tmp->value == value)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (NULL);
}
