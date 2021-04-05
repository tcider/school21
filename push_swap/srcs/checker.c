/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:20:44 by tcider            #+#    #+#             */
/*   Updated: 2021/04/02 12:25:41 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			init_checker_flags(t_flag *flag)
{
	flag->v = 0;
	flag->c = 0;
	flag->fd = 0;
	flag->file_flag = O_RDONLY;
}

static void			print_com_result(t_stack *a, t_stack *b, char *com, \
															t_flag *flag)
{
	if (flag->v)
	{
		write(1, "==", 2);
		ft_putstr_fd(com, 1);
		write(1, "==\na: ", 6);
		ft_stack_print(a);
		write(1, "\nb: ", 4);
		ft_stack_print(b);
		write(1, "\n", 1);
	}
}

static int			apply_code(t_stack *a, t_heapstr *code, \
									char **com, t_flag *flag)
{
	int			i;
	int			(*oper[COMMAND_NUM])(t_stack *, t_stack *);
	t_stack		*b;

	if (!(b = ft_stack_create()))
		return (-1);
	oper_arr_init(oper);
	i = -1;
	print_com_result(a, b, "init", flag);
	while (++i < code->size)
	{
		if (oper[(code->str)[i] - 1](a, b) && ft_stack_free(&b))
			return (-1);
		print_com_result(a, b, com[(code->str)[i] - 1], flag);
	}
	i = b->size;
	ft_stack_free(&b);
	if (!i && ft_stack_issorted(a))
		return (1);
	return (0);
}

static t_heapstr	*get_code(char **command, int fd)
{
	char		*line;
	int			ret;
	int			com_num;
	t_heapstr	*code;

	ret = 1;
	line = NULL;
	code = ft_heapstr_create();
	command_arr_init(command);
	while (ret > 0)
	{
		com_num = 0;
		if ((ret = get_next_line(fd, &line)) > 0)
			com_num = get_command_num(line, command);
		if (line)
			free(line);
		if (ret == -1 || com_num == -1)
		{
			ft_heapstr_free(&code);
			return (NULL);
		}
		if (!ret || ft_heapstr_add(code, (char)com_num))
			break ;
	}
	return (code);
}

int					main(int argc, char **argv)
{
	t_stack		*stack;
	t_heapstr	*code;
	char		*com[COMMAND_NUM];
	t_flag		flag;

	if (argc == 1)
		return (0);
	init_checker_flags(&flag);
	if ((stack = get_stack(argc - 1, argv, &flag)) && \
		(code = get_code(com, flag.fd)))
	{
		argc = apply_code(stack, code, com, &flag);
		if (argc == 1)
			write(1, "OK\n", 3);
		else if (!argc)
			write(1, "KO\n", 3);
		free_stack_fd(&stack, &flag);
		ft_heapstr_free(&code);
		if (argc != -1)
			return (0);
	}
	free_stack_fd(&stack, &flag);
	ft_putendl_fd("Error", 2);
	return (1);
}
