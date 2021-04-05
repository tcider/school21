/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:27:21 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 11:54:41 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_code(t_heapstr *code, t_flag *flag)
{
	int			i;
	int			fd;
	char		*com[COMMAND_NUM];

	i = -1;
	command_arr_init(com);
	if (!flag->fd)
		fd = 1;
	else
		fd = flag->fd;
	if (!code)
		ft_putstr_fd("", fd);
	else
		while (++i < code->size)
			ft_putendl_fd(com[(code->str)[i] - 1], fd);
	ft_heapstr_free(&code);
}

int			exec_command(t_stack *a, t_stack *b, int com_ind, t_heapstr *code)
{
	int			(*oper[COMMAND_NUM])(t_stack *, t_stack *);

	oper_arr_init(oper);
	if (oper[com_ind](a, b) || ft_heapstr_add(code, (char)(com_ind + 1)))
		return (1);
	return (0);
}

static int	*check_sa(t_stack *a, int *arr, \
	int *(*lcis_function)(int *, int, int *))
{
	int			i;
	int			size;
	int			tmp_size;
	int			*tmp_arr;
	t_ilist		*list;

	i = -1;
	size = 0;
	tmp_size = 0;
	tmp_arr = lcis_function(arr, a->size, &size);
	free(tmp_arr);
	while (++i < a->size - 1)
	{
		ft_arr_swap(arr, i, i + 1);
		tmp_arr = lcis_function(arr, a->size, &tmp_size);
		free(tmp_arr);
		if (tmp_size > size && (size = tmp_size))
		{
			list = ft_stack_findbyval(a, arr[i + 1]);
			list->flag = 1;
		}
		else
			ft_arr_swap(arr, i, i + 1);
	}
	return (arr);
}

static int	*prepare_index(t_stack *a, int *(*lcis_function)(int *, int, int *))
{
	int			*arr;
	t_stack		*tmp;
	int			min_pos;

	tmp = ft_stack_copy(a, 0);
	if (!tmp)
		return (NULL);
	min_pos = ft_stack_posminval(tmp);
	if (!min_pos)
		return (NULL);
	while (--min_pos)
		ft_stack_rotate(tmp, 1);
	arr = ft_stack_toarr(tmp);
	ft_stack_free(&tmp);
	if (!arr)
		return (NULL);
	return (check_sa(a, arr, lcis_function));
}

int			index_stack(t_stack *a, int *(*lcis_function)(int *, int, int *))
{
	int			*arr;
	int			*lcis;
	int			lcis_size;
	t_ilist		*tmp;

	lcis_size = 0;
	if (!(arr = prepare_index(a, lcis_function)) || \
		!(lcis = lcis_function(arr, a->size, &lcis_size)))
		return (0);
	ft_arr_sort(arr, a->size);
	tmp = a->head;
	while (tmp)
	{
		tmp->index = ft_arr_findnum(arr, a->size, tmp->value);
		tmp->tmp = ft_arr_findnum(lcis, lcis_size, tmp->value);
		tmp = tmp->next;
	}
	free(arr);
	free(lcis);
	return (lcis_size);
}
