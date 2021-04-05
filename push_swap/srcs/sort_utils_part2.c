/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:26:26 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 12:04:44 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_up(t_stack *a, int sizeb, int posb, int indb)
{
	int			res;
	int			posa;
	int			min;

	res = (sizeb - posb + 1 < posb - 1) ? sizeb - posb + 1 : posb - 1;
	posa = indb + 1;
	if (posa == a->size + sizeb)
		posa = 0;
	posa = ft_stack_posbyind(a, posa);
	if (posa)
	{
		res += (a->size - posa + 1 < posa - 1) ? \
			a->size - posa + 1 : posa - 1;
		min = ft_min(a->size - posa + 1, sizeb - posb + 1) + \
				ft_mod(a->size - posa + 1 - (sizeb - posb + 1));
		if (min < res)
			res = min;
		min = ft_min(posa - 1, posb - 1) + ft_mod(posa - 1 - (posb - 1));
		if (min < res)
			res = min;
	}
	else
		res = -1;
	return (res);
}

static int	count_down(t_stack *a, int sizeb, int posb, int indb)
{
	int			res;
	int			posa;
	int			min;

	res = (sizeb - posb + 1 < posb - 1) ? sizeb - posb + 1 : posb - 1;
	posa = indb - 1;
	if (posa < 0)
		posa = a->size + sizeb - 1;
	posa = ft_stack_posbyind(a, posa);
	if (posa)
	{
		res += (a->size - posa < posa) ? \
			a->size - posa : posa;
		min = ft_min(a->size - posa, sizeb - posb + 1) + \
				ft_mod(a->size - posa - (sizeb - posb + 1));
		if (min < res)
			res = min;
		min = ft_min(posa, posb - 1) + ft_mod(posa - (posb - 1));
		if (min < res)
			res = min;
	}
	else
		res = -1;
	return (res);
}

void		count_cost(t_stack *a, t_stack *b)
{
	t_ilist		*list;
	int			cost_down;
	int			i;

	i = 1;
	list = b->head;
	while (list)
	{
		cost_down = count_down(a, b->size, i, list->index);
		list->tmp = count_up(a, b->size, i, list->index);
		if (cost_down != -1 && (list->tmp == -1 || cost_down < list->tmp))
		{
			list->tmp = cost_down;
			list->flag = 1;
		}
		else
			list->flag = 0;
		list = list->next;
		i++;
	}
}

int			move_aelem_top(t_stack *a, t_stack *b, int pos, t_heapstr *code)
{
	int		err;

	err = 0;
	if (pos > a->size)
		pos = 1;
	if (a->size - pos + 1 < pos - 1)
		while (++pos <= a->size + 1)
			err = exec_command(a, b, RRA, code);
	else
		while (--pos > 0)
			err = exec_command(a, b, RA, code);
	return (err);
}

int			move_belem_top(t_stack *a, t_stack *b, int pos, t_heapstr *code)
{
	int		err;

	err = 0;
	if (b->size - pos + 1 < pos - 1)
		while (++pos <= b->size + 1)
			err = exec_command(a, b, RRB, code);
	else
		while (--pos > 0)
			err = exec_command(a, b, RB, code);
	return (err);
}
