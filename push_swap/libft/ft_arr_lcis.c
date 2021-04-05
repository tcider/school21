/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_lcis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:24:48 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 12:52:59 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_best_ind(int *arr, int *tmp, int start, int stop)
{
	int		max;
	int		i;
	int		maxind;

	max = 0;
	maxind = start;
	i = start;
	while (++i < stop)
		if (arr[i] > arr[start] && tmp[i] > max)
		{
			max = tmp[i];
			maxind = i;
		}
	if (!max)
		maxind = stop;
	return (maxind);
}

static int	find_best(int *arr, int *tmp, int start, int stop)
{
	int		max;
	int		i;

	max = 0;
	i = start;
	while (++i < stop)
		if (arr[i] > arr[start] && tmp[i] > max)
			max = tmp[i];
	return (max);
}

int			*ft_arr_lcis(int *arr, int size, int *lcis_size)
{
	int		*tmp;
	int		*res;
	int		i;

	if (!arr || !size || !(tmp = (int*)malloc(sizeof(int) * size)) || \
		!(res = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	i = size - 1;
	tmp[i] = 1;
	i = size;
	while (--i >= 0)
		tmp[i] = find_best(arr, tmp, i, size) + 1;
	i = ft_arr_maxind(tmp, size);
	*lcis_size = 1;
	res[0] = arr[i];
	while (i < size)
	{
		i = find_best_ind(arr, tmp, i, size);
		if (i != size)
			res[++(*lcis_size) - 1] = arr[i];
	}
	free(tmp);
	return (res);
}
