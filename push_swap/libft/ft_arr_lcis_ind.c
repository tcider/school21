/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_lcis_ind.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:49:26 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 13:45:49 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ifind_best_ind(int *arr, int *tmp, int start, int stop)
{
	int		max;
	int		i;
	int		maxind;

	max = 0;
	maxind = start;
	i = start;
	while (++i < stop)
		if (arr[i] - arr[start] == 1 && tmp[i] > max)
		{
			max = tmp[i];
			maxind = i;
		}
	if (!max)
		maxind = stop;
	return (maxind);
}

static int		ifind_best(int *arr, int *tmp, int start, int stop)
{
	int		max;
	int		i;

	max = 0;
	i = start;
	while (++i < stop)
		if (arr[i] - arr[start] == 1 && tmp[i] > max)
			max = tmp[i];
	return (max);
}

static int		*lcis_ind(int *arr, int size, int *lcis_size)
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
		tmp[i] = ifind_best(arr, tmp, i, size) + 1;
	i = ft_arr_maxind(tmp, size);
	*lcis_size = 1;
	res[0] = arr[i];
	while (i < size)
	{
		i = ifind_best_ind(arr, tmp, i, size);
		if (i != size)
			res[++(*lcis_size) - 1] = arr[i];
	}
	free(tmp);
	return (res);
}

int				*ft_arr_lcisind(int *arr, int size, int *lcis_size)
{
	int		*res;
	int		*tmp_ind;
	int		*arr_copy;
	int		i;
	int		j;

	if (!(tmp_ind = ft_arr_copy(arr, size)) || \
		!(arr_copy = ft_arr_copy(arr, size)))
		return (NULL);
	ft_arr_sort(arr_copy, size);
	i = -1;
	while (++i < size && (j = -1))
		while (++j < size)
			if (tmp_ind[j] == arr_copy[i])
				tmp_ind[j] = i;
	if (!(res = lcis_ind(tmp_ind, size, lcis_size)))
		return (NULL);
	i = -1;
	while (++i < *lcis_size)
		res[i] = arr_copy[res[i]];
	free(tmp_ind);
	free(arr_copy);
	return (res);
}
