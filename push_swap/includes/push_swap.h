/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:02:56 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 12:44:35 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

# define COMMAND_NUM 11

typedef enum	e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_op;

typedef struct	s_flag
{
	char		v;
	char		c;
	int			fd;
	int			file_flag;
}				t_flag;

typedef struct	s_data
{
	t_stack		*a;
	t_stack		*a_copy;
	t_stack		*b;
	t_stack		*tmp;
	t_heapstr	*code;
	t_heapstr	*code_copy;
}				t_data;

typedef struct	s_tmp
{
	int			pa;
	int			pb;
	int			cost;
	int			f;
}				t_tmp;

void			command_arr_init(char **command);
void			oper_arr_init(int (**oper)(t_stack *, t_stack *));
int				get_command_num(char *str, char **command);
t_stack			*get_stack(int size, char **argv, t_flag *flag);
void			free_stack_fd(t_stack **stack, t_flag *flag);
int				oper_sa(t_stack *a, t_stack *b);
int				oper_sb(t_stack *a, t_stack *b);
int				oper_ss(t_stack *a, t_stack *b);
int				oper_pa(t_stack *a, t_stack *b);
int				oper_pb(t_stack *a, t_stack *b);
int				oper_ra(t_stack *a, t_stack *b);
int				oper_rb(t_stack *a, t_stack *b);
int				oper_rr(t_stack *a, t_stack *b);
int				oper_rra(t_stack *a, t_stack *b);
int				oper_rrb(t_stack *a, t_stack *b);
int				oper_rrr(t_stack *a, t_stack *b);
void			print_code(t_heapstr *code, t_flag *flag);
int				exec_command(t_stack *a, t_stack *b, int com_ind, \
				t_heapstr *code);
int				index_stack(t_stack *a, \
				int *(*lcis_function)(int *, int, int *));
int				fast_sort(t_stack *a, t_stack *b, t_heapstr *code, \
				int *(*lcis_function)(int *, int, int *));
void			count_cost(t_stack *a, t_stack *b);
int				move_aelem_top(t_stack *a, t_stack *b, int pos, \
				t_heapstr *code);
int				move_belem_top(t_stack *a, t_stack *b, int pos, \
				t_heapstr *code);

#endif
