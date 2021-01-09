/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 21:39:04 by tcider            #+#    #+#             */
/*   Updated: 2021/01/04 18:09:39 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

int				clear_params(t_prms *prms, int free_memory)
{
	if (free_memory)
	{
		ft_lstclear(&prms->figures, manual_free);
		ft_lstclear(&prms->cameras, manual_free);
		ft_lstclear(&prms->lights, manual_free);
	}
	else
		ft_memset(prms, 0, sizeof(t_prms));
	return (1);
}

void			render_image(t_prms *p)
{
	int			i;
	int			j;
	int			*adr;
	t_xyz		vp;

	adr = p->img_adr;
	i = -1;
	put_msg(RT_GOING_MSG);
	rt_cam_init(p);
	while (++i < p->res.y)
	{
		if (i)
			adr += p->line_size / 4;
		j = -1;
		while (++j < p->res.x)
		{
			vp = xyz_add(xyz_mltnum(p->cam->xd, j), xyz_mltnum(p->cam->yd, i));
			vp = xyz_add(vp, p->cam->vec);
			p->ray = xyz_norm(xyz_sub(vp, p->cam->pos));
			adr[j] = rt_get_target(p);
		}
	}
	put_msg(RT_OK_MSG);
}

static int		hook_key(int key, t_prms *p)
{
	int			num;

	if (key == EXIT_KEY)
		clear_exit(p);
	if (key == PREV_CAM_KEY || key == NEXT_CAM_KEY)
	{
		num = p->cam->num;
		if (key == PREV_CAM_KEY)
			num = (num == 1) ? p->cam_set : num - 1;
		else
			num = (num == p->cam_set) ? 1 : num + 1;
		if (num != p->cam->num)
			return (rt_change_cam(p, num));
	}
	if (key == RXU_KEY || key == RYU_KEY || key == RZU_KEY ||
		key == RXD_KEY || key == RYD_KEY || key == RZD_KEY ||
		key == MXU_KEY || key == MYU_KEY || key == MZU_KEY ||
		key == MXD_KEY || key == MYD_KEY || key == MZD_KEY)
		rt_move_cam(p, key);
	return (0);
}

static int		render_prms(t_prms *p)
{
	if (!(p->mlx = mlx_init()) &&
		(p->error = MLX_ERR))
		return (0);
	if (rt_get_res(p) && !(p->image = mlx_new_image(p->mlx, p->res.x, p->res.y))
		&& (p->error = MLX_IMG_ERR))
		return (0);
	p->cam = p->cameras->content;
	p->img_adr = (int *)mlx_get_data_addr(p->image, &(p->depth),
		&(p->line_size), &(p->endian));
	render_image(p);
	if (p->save && !save_bmp(p))
		return (0);
	else if (!p->save)
	{
		put_msg(RT_HELP1_MSG);
		put_msg(RT_HELP2_MSG);
		if (!(p->window = mlx_new_window(p->mlx, p->res.x, p->res.y, MLX_NAME))
			&& (p->error = MLX_WIN_ERR))
			return (0);
		mlx_put_image_to_window(p->mlx, p->window, p->image, 0, 0);
		mlx_key_hook(p->window, hook_key, p);
		mlx_hook(p->window, 17, (1L << 17), clear_exit, p);
		mlx_loop(p->mlx);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_prms		prms;
	int			tmp;
	int			fd;

	clear_params(&prms, 0);
	if ((argc == 3 && !ft_strcmp(argv[2], "--save") && (prms.save = 1)) ||
		argc == 2)
	{
		if (ft_strcmp(".rt", &argv[1][ft_strlen(argv[1]) - 3]))
			manual_exit(FILE_EXT_ERR);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			manual_exit(strerror(errno));
		tmp = parse_params(fd, &prms);
		close(fd);
		if (tmp)
			tmp = render_prms(&prms);
		clear_params(&prms, 1);
		if (!tmp)
			manual_exit(prms.error);
	}
	else
		manual_exit(ARGS_ERR);
	return (0);
}
