/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:40:05 by tcider            #+#    #+#             */
/*   Updated: 2021/01/04 18:03:26 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_H
# define FT_MINIRT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "constants.h"

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef	struct		s_amlight
{
	double			power;
	t_rgb			rgb;
}					t_amlight;

typedef	struct		s_cam
{
	int				num;
	t_xyz			pos;
	t_xyz			norm;
	double			fov;
	char			cam_set;
	t_xyz			vec;
	t_xyz			vec1;
	t_xyz			vec2;
	t_xyz			vec3;
	t_xyz			xd;
	t_xyz			yd;
}					t_cam;

typedef struct		s_light
{
	t_xyz			pos;
	double			ratio;
	t_rgb			rgb;
	char			type;
	t_xyz			norm;
}					t_light;

typedef struct s_fgr	t_fgr;

typedef struct		s_prms
{
	int				res_set;
	t_res			res;
	int				amb_set;
	t_amlight		amb;
	int				cam_set;
	t_list			*cameras;
	t_list			*figures;
	t_list			*lights;
	char			save;
	char			*error;
	t_cam			*cam;
	void			*mlx;
	void			*window;
	void			*image;
	int				*img_adr;
	int				depth;
	int				line_size;
	int				endian;
	t_fgr			*fgr;
	t_xyz			ray;
}					t_prms;

struct				s_fgr
{
	char			*id;
	t_xyz			xyz1;
	t_xyz			xyz2;
	t_xyz			xyz3;
	double			size1;
	double			size2;
	t_rgb			rgb;
	t_xyz			pnt;
	t_xyz			norm;
	double			(*rt_dist)(t_prms *p, t_fgr *fgr);
	t_xyz			tmp1;
	t_xyz			tmp2;
};

typedef struct		s_bmp_h
{
	char			magicnum[2];
	int				size;
	int				reserved;
	int				offset;
	int				ih_size;
	int				width;
	int				height;
	short			planes;
	short			depth;
	int				compr;
	int				img_size;
	int				x_res;
	int				y_res;
	int				color_used;
	int				color_need;
}					t_bmp_h;

void				put_msg(char *str);
void				manual_exit(char *str);
int					manual_close(int fd);
void				manual_free(void *ptr);
int					clear_exit(t_prms *p);
int					free_str(char **str, int size);
int					clear_params(t_prms *prms, int free_memory);
int					parse_params(int fd, t_prms *prms);
int					parse_xyz(char *line, t_xyz *xyz);
int					parse_norm(char *line, t_xyz *xyz);
int					parse_rgb(char *line, t_rgb *rgb);
int					parse_res(char **line, t_prms *prms);
int					parse_cam(char **line, t_prms *prms);
int					parse_light(char **line, t_prms *prms);
int					parse_amb(char **line, t_prms *prms);
int					make_sp(char **line, t_fgr *fgr, t_prms *p);
int					make_pl(char **line, t_fgr *fgr, t_prms *p);
int					make_sq(char **line, t_fgr *fgr, t_prms *p);
int					make_cy(char **line, t_fgr *fgr, t_prms *p);
int					make_tr(char **line, t_fgr *fgr, t_prms *p);
void				render_image(t_prms *prms);
int					rt_get_res(t_prms *p);
int					rt_change_cam(t_prms *p, int num);
void				rt_cam_init(t_prms *p);
int					rt_get_target(t_prms *prms);
double				rt_dist_sp(t_prms *p, t_fgr *fgr);
double				rt_dist_pl(t_prms *p, t_fgr *fgr);
double				rt_dist_sq(t_prms *p, t_fgr *fgr);
double				rt_dist_cy(t_prms *p, t_fgr *fgr);
double				rt_dist_tr(t_prms *p, t_fgr *fgr);
int					rt_color_rgb(t_rgb rgb);
t_rgb				rt_color_ratio(t_rgb rgb, double ratio);
t_rgb				rt_color_plus(t_rgb rgb1, t_rgb rgb2);
t_rgb				rt_color_filter(t_rgb rgb);
int					rt_color_fgr(t_prms *p);
int					rt_move_cam(t_prms *p, int key);
t_xyz				cy_norm(t_fgr *fgr);
int					save_bmp(t_prms *prms);

#endif
