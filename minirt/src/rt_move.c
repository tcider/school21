/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:49:33 by tcider            #+#    #+#             */
/*   Updated: 2020/12/29 19:18:00 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

static t_xyz	rt_move_norm(t_xyz norm, int key)
{
	t_xyz		new;
	int			i;

	i = ROTATE_ANGLE;
	new = norm;
	if (key == RXU_KEY || (key == RXD_KEY && (i = -i)))
	{
		new.x = norm.x;
		new.y = cos(i * M_PI / 180) * norm.y - sin(i * M_PI / 180) * norm.z;
		new.z = sin(i * M_PI / 180) * norm.y + cos(i * M_PI / 180) * norm.z;
	}
	else if (key == RYU_KEY || (key == RYD_KEY && (i = -i)))
	{
		new.x = cos(i * M_PI / 180) * norm.x + sin(i * M_PI / 180) * norm.z;
		new.y = norm.y;
		new.z = -sin(i * M_PI / 180) * norm.x + cos(i * M_PI / 180) * norm.z;
	}
	else if (key == RZU_KEY || (key == RZD_KEY && (i = -i)))
	{
		new.x = cos(i * M_PI / 180) * norm.x - sin(i * M_PI / 180) * norm.y;
		new.y = sin(i * M_PI / 180) * norm.x + cos(i * M_PI / 180) * norm.y;
		new.z = norm.z;
	}
	return (new);
}

static t_xyz	rt_move_pos(t_xyz pos, int key)
{
	t_xyz		new;
	int			i;

	i = MOVE_LEN;
	new = pos;
	if (key == MXU_KEY || (key == MXD_KEY && (i = -i)))
		new.x += i;
	else if (key == MYU_KEY || (key == MYD_KEY && (i = -i)))
		new.y += i;
	else if (key == MZU_KEY || (key == MZD_KEY && (i = -i)))
		new.z += i;
	return (new);
}

int				rt_move_cam(t_prms *p, int key)
{
	p->cam->cam_set = 0;
	if (key == RXU_KEY || key == RYU_KEY || key == RZU_KEY ||
		key == RXD_KEY || key == RYD_KEY || key == RZD_KEY)
		p->cam->norm = rt_move_norm(p->cam->norm, key);
	else
		p->cam->pos = rt_move_pos(p->cam->pos, key);
	render_image(p);
	mlx_put_image_to_window(p->mlx, p->window, p->image, 0, 0);
	return (1);
}
