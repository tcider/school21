/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:40:06 by tcider            #+#    #+#             */
/*   Updated: 2021/03/28 12:19:11 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stack_isanyflag(t_stack *stack)
{
	t_ilist		*list;

	if (stack && stack->size)
	{
		list = stack->head;
		while (list)
		{
			if (list->flag)
				return (1);
			list = list->next;
		}
	}
	return (0);
}
