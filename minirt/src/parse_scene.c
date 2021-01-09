/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camlight.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 22:07:38 by tcider            #+#    #+#             */
/*   Updated: 2020/12/29 19:04:31 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

int			parse_norm(char *line, t_xyz *xyz)
{
	if (!parse_xyz(line, xyz) ||
		xyz->x < -1.0 || xyz->y < -1.0 || xyz->z < -1.0 ||
		xyz->x > 1.0 || xyz->y > 1.0 || xyz->z > 1.0 ||
		(!xyz->x && !xyz->y && !xyz->z))
		return (0);
	return (1);
}

int			parse_amb(char **line, t_prms *prms)
{
	char		*end;

	end = NULL;
	if ((prms->amb.power = ft_strtof(line[1], &end)) < 0.0 || *end ||
		prms->amb.power > 1.0 || !parse_rgb(line[2], &prms->amb.rgb))
	{
		prms->error = AMB_ERR;
		return (0);
	}
	prms->amb.rgb = rt_color_ratio(prms->amb.rgb, prms->amb.power);
	return (1);
}

int			parse_cam(char **line, t_prms *prms)
{
	t_cam		*cam;
	t_list		*elem;
	char		*end;

	end = NULL;
	if (!(cam = (t_cam*)malloc(sizeof(t_cam))) &&
		(prms->error = strerror(errno)))
		return (0);
	if ((!parse_xyz(line[1], &cam->pos) || !parse_norm(line[2], &cam->norm) ||
		(cam->fov = ft_strtof(line[3], &end)) < 0.0 || cam->fov > 180.0 || *end)
		&& (prms->error = CAM_ERR))
		return (0);
	cam->num = prms->cam_set;
	cam->cam_set = 0;
	if (!(elem = ft_lstnew(cam)) &&
		(prms->error = LIBFT_ERR))
		return (0);
	ft_lstadd_back(&prms->cameras, elem);
	return (1);
}

int			parse_light(char **line, t_prms *prms)
{
	t_light		*light;
	t_list		*elem;
	char		*end;

	end = NULL;
	if (!(light = (t_light*)malloc(sizeof(t_light))) &&
		(prms->error = strerror(errno)))
		return (0);
	if ((!parse_xyz(line[1], &light->pos) || !parse_rgb(line[3], &light->rgb) ||
		(light->ratio = ft_strtof(line[2], &end)) < 0.0 || light->ratio > 1.0 ||
		*end) && (prms->error = LIGHT_ERR))
		return (0);
	light->type = 0;
	if (line[4] && (light->type = 1) && !parse_xyz(line[4], &light->norm) &&
		(prms->error = LIGHT_NORM_ERR))
		return (0);
	if (!(elem = ft_lstnew(light)) &&
		(prms->error = LIBFT_ERR))
		return (0);
	ft_lstadd_back(&prms->lights, elem);
	return (1);
}

int			parse_res(char **line, t_prms *prms)
{
	char		*end;

	end = NULL;
	if ((prms->res.x = ft_strtoi(line[1], &end)) <= 0 || *end ||
			(prms->res.y = ft_strtoi(line[2], &end)) <= 0 || *end)
	{
		prms->error = RES_ERR;
		return (0);
	}
	return (1);
}
