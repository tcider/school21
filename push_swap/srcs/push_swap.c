/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:50:05 by tcider            #+#    #+#             */
/*   Updated: 2021/04/02 12:04:05 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			init_push_flags(t_flag *flag)
{
	flag->v = 0;
	flag->c = 0;
	flag->fd = 0;
	flag->file_flag = O_WRONLY | O_CREAT | O_TRUNC;
}

static void			data_free(t_data *data, int flag)
{
	if (data->a)
		ft_stack_free(&(data->a));
	if (data->a_copy)
		ft_stack_free(&(data->a_copy));
	if (data->b)
		ft_stack_free(&(data->b));
	if (flag && data->code)
		ft_heapstr_free(&(data->code));
	if (flag && data->code_copy)
		ft_heapstr_free(&(data->code_copy));
}

static int			data_init(t_data *data, t_stack *a)
{
	data->a = a;
	data->a_copy = NULL;
	data->b = NULL;
	data->code = NULL;
	data->code_copy = NULL;
	if (!(data->a_copy = ft_stack_copy(a, 0)) || \
		!(data->b = ft_stack_create()) || \
		!(data->code = ft_heapstr_create()) || \
		!(data->code_copy = ft_heapstr_create()))
	{
		data_free(data, 1);
		return (1);
	}
	return (0);
}

static t_heapstr	*sort_stack(t_stack *a)
{
	t_data		data;

	if (data_init(&data, a))
		return (NULL);
	if (fast_sort(data.a, data.b, data.code, ft_arr_lcis) || \
		fast_sort(data.a_copy, data.b, data.code_copy, ft_arr_lcisind))
	{
		data_free(&data, 1);
		return (NULL);
	}
	data_free(&data, 0);
	if (data.code_copy->size < data.code->size)
	{
		ft_heapstr_free(&(data.code));
		return (data.code_copy);
	}
	else
	{
		ft_heapstr_free(&(data.code_copy));
		return (data.code);
	}
}

int					main(int argc, char **argv)
{
	t_stack		*stack;
	t_flag		flag;
	t_heapstr	*code;

	if (argc == 1)
		return (0);
	init_push_flags(&flag);
	if ((stack = get_stack(argc - 1, argv, &flag)))
	{
		if (ft_stack_issorted(stack) && ft_stack_free(&stack))
			code = NULL;
		else if (!(code = sort_stack(stack)))
		{
			free_stack_fd(NULL, &flag);
			ft_putendl_fd("Error", 2);
			return (1);
		}
		print_code(code, &flag);
		if (flag.fd)
			close(flag.fd);
		return (0);
	}
	free_stack_fd(&stack, &flag);
	ft_putendl_fd("Error", 2);
	return (1);
}
