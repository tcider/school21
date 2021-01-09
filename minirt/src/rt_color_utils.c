/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:03:33 by tcider            #+#    #+#             */
/*   Updated: 2020/12/26 22:08:37 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

int				rt_color_rgb(t_rgb rgb)
{
	int			res;

	res = 0;
	res = (((((res + rgb.r) << 8) + rgb.g) << 8) + rgb.b);
	return (res);
}

t_rgb			rt_color_ratio(t_rgb rgb, double ratio)
{
	if (ratio <= 1 && ratio >= 0)
	{
		rgb.r *= ratio;
		rgb.g *= ratio;
		rgb.b *= ratio;
	}
	return (rgb);
}

t_rgb			rt_color_plus(t_rgb rgb1, t_rgb rgb2)
{
	int			tmp;

	if ((tmp = rgb1.r + rgb2.r) > 255)
		rgb1.r = 255;
	else
		rgb1.r = tmp;
	if ((tmp = rgb1.g + rgb2.g) > 255)
		rgb1.g = 255;
	else
		rgb1.g = tmp;
	if ((tmp = rgb1.b + rgb2.b) > 255)
		rgb1.b = 255;
	else
		rgb1.b = tmp;
	return (rgb1);
}

t_rgb			rt_color_filter(t_rgb rgb)
{
	int			r;
	int			g;
	int			b;
	t_rgb		res;

	r = (rgb.r * 0.393) + (rgb.g * 0.769) + (rgb.b * 0.189);
	g = (rgb.r * 0.349) + (rgb.g * 0.686) + (rgb.b * 0.168);
	b = (rgb.r * 0.272) + (rgb.g * 0.534) + (rgb.b * 0.131);
	res.r = (r > 255) ? 255 : r;
	res.g = (g > 255) ? 255 : g;
	res.b = (b > 255) ? 255 : b;
	return (res);
}
