/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:19:32 by tcider            #+#    #+#             */
/*   Updated: 2021/03/17 14:02:08 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		oper_ra(t_stack *a, t_stack *b)
{
	ft_stack_rotate(a, 1);
	if (!b)
		return (1);
	return (0);
}

int		oper_rb(t_stack *a, t_stack *b)
{
	ft_stack_rotate(b, 1);
	if (!a)
		return (1);
	return (0);
}

int		oper_rr(t_stack *a, t_stack *b)
{
	ft_stack_rotate(a, 1);
	ft_stack_rotate(b, 1);
	return (0);
}
