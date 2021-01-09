/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fgr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:32:01 by tcider            #+#    #+#             */
/*   Updated: 2020/12/29 19:01:32 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

int		make_sp(char **line, t_fgr *fgr, t_prms *p)
{
	char		*end;

	end = NULL;
	if (!parse_xyz(line[1], &fgr->xyz1) || !parse_rgb(line[3], &fgr->rgb) ||
		(fgr->size1 = ft_strtof(line[2], &end)) < 0 || *end)
	{
		p->error = SP_ERR;
		return (0);
	}
	fgr->rt_dist = &rt_dist_sp;
	return (1);
}

int		make_pl(char **line, t_fgr *fgr, t_prms *p)
{
	char		*end;

	end = NULL;
	if (!parse_xyz(line[1], &fgr->xyz1) || !parse_norm(line[2], &fgr->xyz2) ||
		!parse_rgb(line[3], &fgr->rgb))
	{
		p->error = PL_ERR;
		return (0);
	}
	fgr->rt_dist = &rt_dist_pl;
	return (1);
}

int		make_sq(char **line, t_fgr *fgr, t_prms *p)
{
	char		*end;

	end = NULL;
	if (!parse_xyz(line[1], &fgr->xyz1) || !parse_norm(line[2], &fgr->xyz2) ||
		(fgr->size1 = ft_strtof(line[3], &end)) < 0 || *end ||
		!parse_rgb(line[4], &fgr->rgb))
	{
		p->error = SQ_ERR;
		return (0);
	}
	fgr->rt_dist = &rt_dist_sq;
	return (1);
}

int		make_cy(char **line, t_fgr *fgr, t_prms *p)
{
	char		*end;

	end = NULL;
	if (!parse_xyz(line[1], &fgr->xyz1) || !parse_norm(line[2], &fgr->xyz2) ||
		(fgr->size1 = ft_strtof(line[3], &end)) < 0 || *end ||
		(fgr->size2 = ft_strtof(line[4], &end)) < 0 || *end ||
		!parse_rgb(line[5], &fgr->rgb))
	{
		p->error = CY_ERR;
		return (0);
	}
	fgr->rt_dist = &rt_dist_cy;
	return (1);
}

int		make_tr(char **line, t_fgr *fgr, t_prms *p)
{
	char		*end;

	end = NULL;
	if (!parse_xyz(line[1], &fgr->xyz1) || !parse_xyz(line[2], &fgr->xyz2) ||
		!parse_xyz(line[3], &fgr->xyz3) || !parse_rgb(line[4], &fgr->rgb))
	{
		p->error = TR_ERR;
		return (0);
	}
	fgr->rt_dist = &rt_dist_tr;
	return (1);
}
