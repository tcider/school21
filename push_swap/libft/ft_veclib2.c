/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veclib2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:34:41 by tcider            #+#    #+#             */
/*   Updated: 2020/12/26 16:52:22 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_xyz				xyz_minus(t_xyz a)
{
	if (a.x != 0)
		a.x = -a.x;
	if (a.y != 0)
		a.y = -a.y;
	if (a.z != 0)
		a.z = -a.z;
	return (a);
}

double				xyz_mltxyz(t_xyz a, t_xyz b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_xyz				xyz_intersect(t_xyz a, t_xyz b)
{
	t_xyz	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

t_xyz				xyz_new(double x, double y, double z)
{
	t_xyz	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}
