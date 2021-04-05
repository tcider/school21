/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_part3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:26:26 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 12:46:40 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		init_cost_data(t_stack *a, t_stack *b, t_tmp *tmp)
{
	t_ilist		*blist;
	int			inda;

	count_cost(a, b);
	blist = ft_stack_findmintmp(b);
	if (blist->flag)
	{
		inda = blist->index - 1;
		if (inda < 0)
			inda = a->size + b->size - 1;
	}
	else
	{
		inda = blist->index + 1;
		if (inda == a->size + b->size)
			inda = 0;
	}
	tmp->pa = ft_stack_posbyind(a, inda);
	tmp->pb = ft_stack_posbyind(b, blist->index);
	tmp->f = blist->flag;
	tmp->cost = blist->tmp;
}

static void		rr_both(t_stack *a, t_stack *b, t_heapstr *code, t_tmp *tmp)
{
	int			i;

	i = 0;
	while (++i <= ft_min(tmp->pa - 1 + tmp->f, tmp->pb - 1))
		exec_command(a, b, RR, code);
	i = 0;
	if (tmp->pa - 1 + tmp->f <= tmp->pb - 1)
		while (++i <= tmp->pb - 1 - (tmp->pa - 1 + tmp->f))
			exec_command(a, b, RB, code);
	else
		while (++i <= tmp->pa - 1 + tmp->f - (tmp->pb - 1))
			exec_command(a, b, RA, code);
}

static void		rrr_both(t_stack *a, t_stack *b, t_heapstr *code, t_tmp *tmp)
{
	int			i;

	i = 0;
	while (++i <= ft_min(a->size - tmp->pa + 1 - tmp->f, b->size - tmp->pb + 1))
		exec_command(a, b, RRR, code);
	i = 0;
	if (a->size - tmp->pa + 1 - tmp->f <= b->size - tmp->pb + 1)
		while (++i <= b->size - tmp->pb + 1 - (a->size - tmp->pa + 1 - tmp->f))
			exec_command(a, b, RRB, code);
	else
		while (++i <= a->size - tmp->pa + 1 - tmp->f - (b->size - tmp->pb + 1))
			exec_command(a, b, RRA, code);
}

static int		exec_min(t_stack *a, t_stack *b, t_heapstr *code)
{
	t_tmp		tmp;

	init_cost_data(a, b, &tmp);
	if (tmp.cost == ft_min(a->size - tmp.pa + 1 - tmp.f, tmp.pa - 1 + tmp.f) + \
		ft_min(b->size - tmp.pb + 1, tmp.pb - 1))
	{
		move_aelem_top(a, b, tmp.pa + tmp.f, code);
		move_belem_top(a, b, tmp.pb, code);
	}
	else if (tmp.cost == ft_min(tmp.pa - 1 + tmp.f, tmp.pb - 1) + \
		ft_mod(tmp.pa - 1 + tmp.f - (tmp.pb - 1)))
		rr_both(a, b, code, &tmp);
	else if (tmp.cost == \
		ft_min(a->size - tmp.pa + 1 - tmp.f, b->size - tmp.pb + 1) + \
		ft_mod(a->size - tmp.pa + 1 - tmp.f - (b->size - tmp.pb + 1)))
		rrr_both(a, b, code, &tmp);
	return (exec_command(a, b, PA, code));
}

int				fast_sort(t_stack *a, t_stack *b, t_heapstr *code, \
	int *(*lcis_function)(int *, int, int *))
{
	int			tmp;
	int			err;

	err = 0;
	if (!(tmp = index_stack(a, lcis_function)))
		return (1);
	while (tmp < a->size || ft_stack_isanyflag(a))
	{
		if (a->head->flag)
		{
			a->head->flag = 0;
			err = exec_command(a, b, SA, code);
		}
		else if (a->head->tmp != -1)
			err = exec_command(a, b, RA, code);
		else
			err = exec_command(a, b, PB, code);
		if (err)
			return (1);
	}
	while (b->size)
		if (exec_min(a, b, code))
			return (1);
	tmp = ft_stack_posbyind(a, 0);
	return (move_aelem_top(a, b, tmp, code));
}
