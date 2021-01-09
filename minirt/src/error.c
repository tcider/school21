/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:36:05 by tcider            #+#    #+#             */
/*   Updated: 2020/12/22 12:36:12 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

void			put_msg(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

int				clear_exit(t_prms *p)
{
	mlx_destroy_image(p->mlx, p->image);
	mlx_destroy_window(p->mlx, p->window);
	clear_params(p, 1);
	put_msg(BYE_MSG);
	exit(EXIT_SUCCESS);
	return (1);
}

void			manual_exit(char *str)
{
	write(FD_ERR, "Error\n", 6);
	if (str && *str)
	{
		write(FD_ERR, str, ft_strlen(str));
		write(FD_ERR, "\n", 1);
	}
	exit(EXIT_FAILURE);
}

int				free_str(char **str, int size)
{
	int			i;

	if (!size)
	{
		if (*str)
			free(*str);
		*str = NULL;
	}
	else if (str)
	{
		i = -1;
		while (str[++i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		free(str);
	}
	return (1);
}

void			manual_free(void *ptr)
{
	if (ptr)
	{
		ft_memset(ptr, 0, sizeof(*ptr));
		free(ptr);
	}
}
