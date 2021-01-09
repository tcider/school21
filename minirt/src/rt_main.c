/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:36:58 by tcider            #+#    #+#             */
/*   Updated: 2021/01/04 17:49:05 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

int			rt_change_cam(t_prms *p, int num)
{
	t_list		*tmp;

	tmp = p->cameras;
	while (tmp)
	{
		if (((t_cam *)(tmp->content))->num == num)
		{
			p->cam = tmp->content;
			render_image(p);
			mlx_put_image_to_window(p->mlx, p->window, p->image, 0, 0);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			rt_get_res(t_prms *p)
{
	int			x;
	int			y;
	int			flag;

	if (p->save)
		return (1);
	x = 0;
	y = 0;
	flag = 0;
	mlx_get_screen_size(p->mlx, &x, &y);
	if (p->res.x > x && (flag = 1))
		p->res.x = x;
	if (p->res.y > y && (flag = 1))
		p->res.y = y;
	if (flag)
		put_msg(RT_RES_MSG);
	return (1);
}

void		rt_cam_init(t_prms *p)
{
	t_xyz		scr_cntr;
	double		h;
	t_xyz		ax;
	t_xyz		ox;
	t_xyz		oy;

	if (p->cam->cam_set)
		return ;
	h = ((p->res.x + 1) / 2.0) / sin(p->cam->fov * M_PI / 360);
	h = sqrt(h * h - pow((p->res.x + 1) / 2.0, 2));
	scr_cntr = xyz_add(p->cam->pos, xyz_mltnum(p->cam->norm, h));
	ax = (fabs(p->cam->norm.y) == 1) ? xyz_new(0, 0, 1) : xyz_new(0, 1, 0);
	ox = xyz_norm(xyz_intersect(p->cam->norm, ax));
	oy = xyz_norm(xyz_intersect(p->cam->norm, ox));
	ox = xyz_mltnum(ox, (p->res.x + 1) / 2.0);
	oy = xyz_mltnum(oy, (p->res.y + 1) / 2.0);
	p->cam->vec = xyz_add(xyz_add(ox, oy), scr_cntr);
	p->cam->vec1 = xyz_add(xyz_add(xyz_minus(ox), oy), scr_cntr);
	p->cam->vec2 = xyz_add(xyz_add(xyz_minus(ox), xyz_minus(oy)), scr_cntr);
	p->cam->vec3 = xyz_add(xyz_add(ox, xyz_minus(oy)), scr_cntr);
	p->cam->xd = xyz_norm(xyz_sub(p->cam->vec1, p->cam->vec));
	p->cam->yd = xyz_norm(xyz_sub(p->cam->vec3, p->cam->vec));
	p->cam->cam_set = 1;
}

int			rt_get_target(t_prms *p)
{
	t_list		*list;
	t_fgr		*fgr;
	double		min;
	double		len;

	list = p->figures;
	min = 0;
	len = 0;
	while (list)
	{
		fgr = (t_fgr *)(list->content);
		len = fgr->rt_dist(p, fgr);
		if (len && (!min || len < min))
		{
			min = len;
			p->fgr = fgr;
		}
		list = list->next;
	}
	if (!min)
		return (0);
	return (rt_color_fgr(p));
}
