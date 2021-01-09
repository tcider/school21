/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 22:16:19 by tcider            #+#    #+#             */
/*   Updated: 2021/01/03 19:06:14 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

int			parse_xyz(char *line, t_xyz *xyz)
{
	char		*end;
	char		**st;
	int			n;

	end = NULL;
	n = 0;
	if (!(st = ft_splitn(line, ',', &n)) || n != 3 ||
		(xyz->x = ft_strtof(st[0], &end)) * 0 || *end ||
		(xyz->y = ft_strtof(st[1], &end)) * 0 || *end ||
		(xyz->z = ft_strtof(st[2], &end)) * 0 || *end)
		return (0);
	return (free_str(st, 1));
}

int			parse_rgb(char *line, t_rgb *rgb)
{
	char		*end;
	char		**st;
	int			n;
	int			res;

	end = NULL;
	n = 0;
	if (!(st = ft_splitn(line, ',', &n)) || n != 3 ||
		(res = ft_strtoi(st[0], &end)) > 255 ||
		(rgb->r = res) < 0 || *end ||
		(res = ft_strtoi(st[1], &end)) > 255 ||
		(rgb->g = res) < 0 || *end ||
		(res = ft_strtoi(st[2], &end)) > 255 ||
		(rgb->b = res) < 0 || *end)
		return (0);
	return (free_str(st, 1));
}

static int	parse_fgr(char **line, char *id, t_prms *p)
{
	t_fgr		*fgr;
	t_list		*elem;
	int			ret;

	ret = 0;
	if (!(fgr = (t_fgr*)malloc(sizeof(t_fgr))) &&
		(p->error = strerror(errno)))
		return (0);
	ft_memset(fgr, 0, sizeof(t_fgr));
	fgr->id = id;
	if (id[1] == 'p')
		ret = make_sp(line, fgr, p);
	else if (id[1] == 'l')
		ret = make_pl(line, fgr, p);
	else if (id[1] == 'q')
		ret = make_sq(line, fgr, p);
	else if (id[1] == 'y')
		ret = make_cy(line, fgr, p);
	else if (id[1] == 'r')
		ret = make_tr(line, fgr, p);
	if (ret && (elem = ft_lstnew(fgr)))
		ft_lstadd_back(&p->figures, elem);
	return (ret);
}

static int	parse_line(char **line, t_prms *prms, int n)
{
	if (line[0][0] == 'R' && !line[0][1] && n == 3 && (++prms->res_set))
		return (parse_res(line, prms));
	else if (line[0][0] == 'A' && !line[0][1] && n == 3 && (++prms->amb_set))
		return (parse_amb(line, prms));
	else if (line[0][0] == 'c' && !line[0][1] && n == 4 && (++prms->cam_set))
		return (parse_cam(line, prms));
	else if (line[0][0] == 'l' && !line[0][1] && (n == 4 || n == 5))
		return (parse_light(line, prms));
	else if (!ft_strcmp("sp", line[0]) && n == 4)
		return (parse_fgr(line, "sp", prms));
	else if (!ft_strcmp("pl", line[0]) && n == 4)
		return (parse_fgr(line, "pl", prms));
	else if (!ft_strcmp("sq", line[0]) && n == 5)
		return (parse_fgr(line, "sq", prms));
	else if (!ft_strcmp("cy", line[0]) && n == 6)
		return (parse_fgr(line, "cy", prms));
	else if (!ft_strcmp("tr", line[0]) && n == 5)
		return (parse_fgr(line, "tr", prms));
	else
	{
		prms->error = TYPE_ERR;
		return (0);
	}
}

int			parse_params(int fd, t_prms *prms)
{
	char		*line;
	char		**split_line;
	int			ret;
	int			flag;
	int			n;

	line = NULL;
	ret = 1;
	flag = 1;
	while (ret > 0 && flag)
	{
		n = 0;
		ret = get_next_line(fd, &line);
		if ((ret == -1 || !(split_line = ft_splitw(line, &n))) &&
			free_str(&line, 0) && (prms->error = GNL_ERR))
			return (0);
		if (free_str(&line, 0) && n > 1 && **split_line)
			flag = parse_line(split_line, prms, n);
		free_str(split_line, 1);
	}
	if ((prms->res_set != 1 || prms->amb_set != 1 || !prms->cam_set) &&
		(prms->error = TYPE_NUM_ERR))
		return (0);
	return (flag);
}
