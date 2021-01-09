/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_dist_cy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:13:01 by tcider            #+#    #+#             */
/*   Updated: 2021/01/04 17:46:33 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

static int		solve_square_eq(double *k, double *x)
{
	double		tmp1;
	double		tmp2;

	if (!k[0])
		return (0);
	tmp1 = k[1] * k[1] - 4 * k[0] * k[2];
	if (tmp1 < 0)
		return (0);
	tmp2 = sqrt(tmp1);
	x[0] = (tmp2 - k[1]) / (2 * k[0]);
	x[1] = (-tmp2 - k[1]) / (2 * k[0]);
	return (1);
}

static double	check_solve(t_prms *p, t_fgr *fgr, double x)
{
	t_xyz		tmp;

	if (x < DIST)
		return (0);
	tmp = xyz_add(p->cam->pos, xyz_mltnum(p->ray, x));
	if (xyz_mltxyz(fgr->xyz2, xyz_sub(tmp, fgr->tmp1)) >= 0 &&
		xyz_mltxyz(fgr->xyz2, xyz_sub(tmp, fgr->tmp2)) <= 0)
		return (x);
	return (0);
}

static double	plane_norm(t_fgr *fgr)
{
	double		tmp;
	t_xyz		inter;
	double		len;

	tmp = xyz_mltxyz(fgr->xyz2, fgr->xyz2);
	if (tmp)
	{
		inter = xyz_sub(fgr->pnt, fgr->tmp1);
		len = xyz_mltxyz(inter, fgr->xyz2) / tmp;
		if (len >= DIST)
			return (len);
	}
	return (0);
}

t_xyz			cy_norm(t_fgr *fgr)
{
	t_xyz		cntr;
	double		tmp;

	if (!(tmp = plane_norm(fgr)))
		return (xyz_new(0, 0, 0));
	cntr = xyz_add(fgr->tmp1, xyz_mltnum(fgr->xyz2, tmp));
	return (xyz_norm(xyz_sub(fgr->pnt, cntr)));
}

double			rt_dist_cy(t_prms *p, t_fgr *fgr)
{
	t_xyz		tmp;
	double		k[3];
	double		x[2];
	double		len;

	fgr->tmp1 = xyz_add(fgr->xyz1, xyz_mltnum(fgr->xyz2, -fgr->size2 / 2));
	fgr->tmp2 = xyz_add(fgr->xyz1, xyz_mltnum(fgr->xyz2, fgr->size2 / 2));
	tmp = xyz_sub(p->cam->pos, fgr->tmp1);
	k[0] = xyz_mltxyz(p->ray, p->ray) - xyz_mltxyz(p->ray, fgr->xyz2) * \
		xyz_mltxyz(p->ray, fgr->xyz2);
	k[1] = 2 * (xyz_mltxyz(p->ray, tmp) - xyz_mltxyz(p->ray, fgr->xyz2) * \
		xyz_mltxyz(tmp, fgr->xyz2));
	k[2] = xyz_mltxyz(tmp, tmp) - pow(xyz_mltxyz(tmp, fgr->xyz2), 2) - \
		fgr->size1 * fgr->size1 / 4;
	if (!solve_square_eq(k, x))
		return (0);
	x[0] = check_solve(p, fgr, x[0]);
	x[1] = check_solve(p, fgr, x[1]);
	len = (!(x[1] * x[0])) ? fmax(x[0], x[1]) : fmin(x[0], x[1]);
	fgr->pnt = xyz_add(p->cam->pos, xyz_mltnum(p->ray, len));
	fgr->norm = cy_norm(fgr);
	return (len);
}
