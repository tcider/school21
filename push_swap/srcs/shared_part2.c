/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:03:08 by tcider            #+#    #+#             */
/*   Updated: 2021/04/02 09:55:22 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_command_num(char *str, char **command)
{
	int			i;

	i = -1;
	while (++i < COMMAND_NUM)
		if (ft_strcmp(str, command[i]) == 0)
			return (i + 1);
	return (-1);
}

void		free_stack_fd(t_stack **stack, t_flag *flag)
{
	if (stack)
		ft_stack_free(stack);
	if (flag->fd)
		close(flag->fd);
	flag->fd = 0;
}
