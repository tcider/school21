/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_part1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:01:26 by tcider            #+#    #+#             */
/*   Updated: 2021/04/02 11:48:25 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_flags(char **argv, t_flag *flag)
{
	int			i;
	int			size;

	i = 0;
	size = 0;
	while (argv[++i] && argv[i][0] == '-')
		if (!ft_strcmp(argv[i], "-v") && !flag->v && (flag->v = 1))
			size += 1;
		else if (!ft_strcmp(argv[i], "-c") && !flag->c && (flag->c = 1))
			size += 1;
		else if (!ft_strcmp(argv[i], "-f"))
		{
			if ((flag->fd = open(argv[i + 1], flag->file_flag, 0666)) != -1 && \
				(size += 2))
				i += 1;
		}
	return (size);
}

t_stack		*get_stack(int size, char **argv, t_flag *flag)
{
	t_stack		*stack;
	int			error;
	char		*end;
	int			num;
	int			start;

	error = 0;
	start = get_flags(argv, flag);
	if (start == size || !(stack = ft_stack_create()))
		return (NULL);
	while (size > start)
	{
		end = NULL;
		num = ft_strtoi_int(argv[size], &end);
		if ((*end || !ft_strcmp(argv[size], "") || \
			ft_stack_posbyval(stack, num)) && ft_stack_free(&stack))
			return (NULL);
		ft_stack_push(stack, num, &error);
		if (error && ft_stack_free(&stack))
			return (NULL);
		size -= 1;
	}
	return (stack);
}

void		command_arr_init(char **command)
{
	command[SA] = "sa";
	command[SB] = "sb";
	command[SS] = "ss";
	command[PA] = "pa";
	command[PB] = "pb";
	command[RA] = "ra";
	command[RB] = "rb";
	command[RR] = "rr";
	command[RRA] = "rra";
	command[RRB] = "rrb";
	command[RRR] = "rrr";
}

void		oper_arr_init(int (**oper)(t_stack *, t_stack *))
{
	oper[SA] = &oper_sa;
	oper[SB] = &oper_sb;
	oper[SS] = &oper_ss;
	oper[PA] = &oper_pa;
	oper[PB] = &oper_pb;
	oper[RA] = &oper_ra;
	oper[RB] = &oper_rb;
	oper[RR] = &oper_rr;
	oper[RRA] = &oper_rra;
	oper[RRB] = &oper_rrb;
	oper[RRR] = &oper_rrr;
}
