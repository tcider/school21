/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veclib1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:34:41 by tcider            #+#    #+#             */
/*   Updated: 2020/12/26 15:25:51 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_xyz				xyz_sub(t_xyz a, t_xyz b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_xyz				xyz_add(t_xyz a, t_xyz b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_xyz				xyz_mltnum(t_xyz a, double b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return (a);
}

double				xyz_len(t_xyz a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
}

t_xyz				xyz_norm(t_xyz a)
{
	double			norm;

	if (!(norm = xyz_len(a)))
		return (a);
	a.x /= norm;
	a.y /= norm;
	a.z /= norm;
	return (a);
}
