/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:23:18 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 11:46:20 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arr_findnum(int *arr, int len, int num)
{
	int		i;

	i = -1;
	while (++i < len)
		if (num == arr[i])
			return (i);
	return (-1);
}

void	ft_arr_sort(int *arr, int size)
{
	int		i;
	int		j;
	int		tmp;
	int		flag;

	j = -1;
	flag = 1;
	while (flag && ++j < size - 1)
	{
		flag = 0;
		i = -1;
		while (++i < size - 1)
			if (arr[i + 1] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = 1;
			}
	}
}

int		ft_arr_maxind(int *arr, int size)
{
	int		i;
	int		max;
	int		ind_max;

	i = -1;
	ind_max = 0;
	max = arr[ind_max];
	while (++i < size)
		if (arr[i] > max)
		{
			ind_max = i;
			max = arr[i];
		}
	return (ind_max);
}

int		*ft_arr_copy(int *arr, int size)
{
	int		i;
	int		*res;

	i = -1;
	if (!(res = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	while (++i < size)
		res[i] = arr[i];
	return (res);
}

void	ft_arr_swap(int *arr, int i, int j)
{
	int		tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
