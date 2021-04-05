/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:19:32 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 11:31:45 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		oper_sa(t_stack *a, t_stack *b)
{
	ft_stack_swap(a);
	if (!b)
		return (1);
	return (0);
}

int		oper_sb(t_stack *a, t_stack *b)
{
	ft_stack_swap(b);
	if (!a)
		return (1);
	return (0);
}

int		oper_ss(t_stack *a, t_stack *b)
{
	ft_stack_swap(a);
	ft_stack_swap(b);
	return (0);
}

int		oper_pa(t_stack *a, t_stack *b)
{
	int		error;

	error = 0;
	if (b && b->size > 0)
	{
		ft_stack_pushfull(a, b->head, &error);
		ft_stack_pop(b, &error);
	}
	if (error)
		return (1);
	return (0);
}

int		oper_pb(t_stack *a, t_stack *b)
{
	int		error;

	error = 0;
	if (a && a->size > 0)
	{
		ft_stack_pushfull(b, a->head, &error);
		ft_stack_pop(a, &error);
	}
	if (error)
		return (1);
	return (0);
}
