/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:37:59 by tcider            #+#    #+#             */
/*   Updated: 2021/01/04 17:45:52 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

static double	rt_directed_light(t_prms *p, t_light *light)
{
	double			tmp;
	t_xyz			inter;
	double			len;

	len = 0;
	if (xyz_mltxyz(xyz_norm(xyz_sub(light->pos, p->fgr->pnt)), light->norm) < 0)
		return (0);
	tmp = xyz_mltxyz(light->norm, light->norm);
	if (tmp)
	{
		inter = xyz_sub(light->pos, p->fgr->pnt);
		len = xyz_mltxyz(inter, light->norm) / tmp;
		if (len < DIST)
			len = 0;
	}
	light->pos = xyz_add(p->fgr->pnt, xyz_mltnum(light->norm, len));
	return (len);
}

static int		rt_color_shadow(t_prms *p, t_light *light)
{
	t_xyz		tmp[2];
	t_list		*list;
	double		sz[3];

	if (light->type && rt_directed_light(p, light) < DIST)
		return (1);
	tmp[0] = p->ray;
	tmp[1] = p->cam->pos;
	p->ray = xyz_minus(light->norm);
	p->cam->pos = light->pos;
	sz[0] = 0;
	sz[2] = xyz_len(xyz_sub(light->pos, p->fgr->pnt));
	list = p->figures;
	while (list)
	{
		sz[1] = ((t_fgr *)list->content)->rt_dist(p, ((t_fgr *)list->content));
		if (sz[1] && (!sz[0] || sz[1] < sz[0]))
			sz[0] = sz[1];
		list = list->next;
	}
	p->ray = tmp[0];
	p->cam->pos = tmp[1];
	if (fabs(sz[0] - sz[2]) <= PRECISION)
		return (0);
	return (1);
}

static t_rgb	rt_color_pnt(t_prms *p, t_light *light)
{
	t_xyz		fgr_norm;
	t_xyz		v;
	t_xyz		tmp;
	double		res;

	fgr_norm = p->fgr->norm;
	if (xyz_mltxyz(fgr_norm, p->ray) > 0)
		fgr_norm = xyz_minus(fgr_norm);
	v = xyz_minus(p->ray);
	res = 2.0 * xyz_mltxyz(fgr_norm, light->norm);
	tmp = xyz_norm(xyz_sub(xyz_mltnum(fgr_norm, res), light->norm));
	res = light->ratio * fmax(xyz_mltxyz(fgr_norm, light->norm), 0);
	if (SHINE)
		res += light->ratio * pow(fmax(xyz_mltxyz(tmp, v), 0), SHINE);
	res = (res > 1) ? 1 : res;
	res = (res < 0) ? 0 : res;
	return (rt_color_ratio(light->rgb, res));
}

int				rt_color_fgr(t_prms *p)
{
	double		ref;
	t_list		*lights;
	t_rgb		sum;
	t_light		*light;

	lights = p->lights;
	sum = p->amb.rgb;
	while (lights)
	{
		light = (t_light *)(lights->content);
		if (!light->type)
			light->norm = xyz_norm(xyz_sub(light->pos, p->fgr->pnt));
		ref = xyz_mltxyz(p->fgr->norm, light->norm);
		if ((xyz_mltxyz(p->fgr->norm, p->ray) > 0) != (ref > 0) &&
			!(rt_color_shadow(p, light)))
			sum = rt_color_plus(sum, rt_color_pnt(p, light));
		lights = lights->next;
	}
	sum.r = sum.r * p->fgr->rgb.r / 255;
	sum.g = sum.g * p->fgr->rgb.g / 255;
	sum.b = sum.b * p->fgr->rgb.b / 255;
	if (FILTER)
		sum = rt_color_filter(sum);
	return (rt_color_rgb(sum));
}
