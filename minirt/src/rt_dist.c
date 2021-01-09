/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_dist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:15:56 by tcider            #+#    #+#             */
/*   Updated: 2021/01/04 17:46:21 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

double		rt_dist_sp(t_prms *p, t_fgr *fgr)
{
	double			k1;
	double			k2;
	double			k3;
	t_xyz			co;
	double			len;

	k1 = xyz_mltxyz(p->ray, p->ray);
	co = xyz_sub(p->cam->pos, fgr->xyz1);
	k2 = 2 * xyz_mltxyz(co, p->ray);
	k3 = xyz_mltxyz(co, co) - pow(fgr->size1 / 2, 2);
	if ((k3 = k2 * k2 - 4 * k1 * k3) < 0)
		return (0);
	if ((len = (-k2 - sqrt(k3)) / (2 * k1)) < DIST)
		len = (-k2 + sqrt(k3)) / (2 * k1);
	if (len < DIST)
		return (0);
	fgr->pnt = xyz_add(p->cam->pos, xyz_mltnum(p->ray, len));
	fgr->norm = xyz_norm(xyz_sub(fgr->pnt, fgr->xyz1));
	return (len);
}

double		rt_dist_pl(t_prms *p, t_fgr *fgr)
{
	double			tmp;
	t_xyz			inter;
	double			len;

	tmp = xyz_mltxyz(p->ray, fgr->xyz2);
	if (tmp)
	{
		inter = xyz_sub(fgr->xyz1, p->cam->pos);
		len = xyz_mltxyz(inter, fgr->xyz2) / tmp;
		if (len >= DIST)
		{
			fgr->norm = fgr->xyz2;
			fgr->pnt = xyz_add(p->cam->pos, xyz_mltnum(p->ray, len));
			return (len);
		}
	}
	return (0);
}

double		rt_dist_sq(t_prms *p, t_fgr *fgr)
{
	double			len;
	t_xyz			vec1;
	t_xyz			vec2;
	t_xyz			vec3;

	if (!(len = rt_dist_pl(p, fgr)))
		return (0);
	vec1 = (fabs(fgr->xyz2.y) == 1) ? xyz_new(1, 0, 0) : xyz_new(0, 1, 0);
	vec1 = xyz_norm(xyz_intersect(fgr->xyz2, vec1));
	vec2 = xyz_norm(xyz_intersect(fgr->xyz2, vec1));
	vec3 = xyz_sub(fgr->pnt, fgr->xyz1);
	if (fgr->size1 / 2 - fabs(xyz_mltxyz(vec3, vec1)) >= DIST &&
		fgr->size1 / 2 - fabs(xyz_mltxyz(vec3, vec2)) >= DIST)
		return (len);
	return (0);
}

double		rt_dist_tr(t_prms *p, t_fgr *fgr)
{
	t_xyz			vec[4];
	double			tmp[4];

	vec[0] = xyz_sub(fgr->xyz2, fgr->xyz1);
	vec[1] = xyz_sub(fgr->xyz3, fgr->xyz1);
	vec[2] = xyz_intersect(p->ray, vec[1]);
	if (!(tmp[1] = xyz_mltxyz(vec[0], vec[2])))
		return (0);
	vec[3] = xyz_sub(p->cam->pos, fgr->xyz1);
	if ((tmp[2] = xyz_mltxyz(vec[3], vec[2]) / tmp[1]) < -DIST ||
		tmp[2] - 1 > DIST)
		return (0);
	vec[2] = xyz_intersect(vec[3], vec[0]);
	if ((tmp[3] = xyz_mltxyz(p->ray, vec[2]) / tmp[1]) < -DIST ||
		tmp[3] + tmp[2] - 1 > DIST)
		return (0);
	fgr->norm = xyz_norm(xyz_intersect(vec[0], vec[1]));
	tmp[0] = xyz_mltxyz(vec[1], vec[2]) / tmp[1];
	fgr->pnt = xyz_add(p->cam->pos, xyz_mltnum(p->ray, tmp[0]));
	return (tmp[0]);
}
