/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:02:02 by tcider            #+#    #+#             */
/*   Updated: 2020/12/21 17:20:13 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

static void	save_init_header(t_prms *p, t_bmp_h *head)
{
	ft_memset(head, 0, sizeof(t_bmp_h));
	head->magicnum[0] = 0x42;
	head->magicnum[1] = 0x4D;
	head->offset = 54;
	head->depth = 24;
	head->size = head->offset + p->res.x * p->res.y * (head->depth / 8);
	head->ih_size = 40;
	head->width = p->res.x;
	head->height = p->res.y;
	head->planes = 1;
	head->img_size = head->size - head->offset;
}

static void	save_headers(int fd, t_bmp_h *head)
{
	write(fd, head->magicnum, 2);
	write(fd, &(head->size), 4);
	write(fd, &(head->reserved), 4);
	write(fd, &(head->offset), 4);
	write(fd, &(head->ih_size), 4);
	write(fd, &(head->width), 4);
	write(fd, &(head->height), 4);
	write(fd, &(head->planes), 2);
	write(fd, &(head->depth), 2);
	write(fd, &(head->compr), 4);
	write(fd, &(head->img_size), 4);
	write(fd, &(head->x_res), 4);
	write(fd, &(head->y_res), 4);
	write(fd, &(head->color_used), 4);
	write(fd, &(head->color_need), 4);
}

int			save_bmp(t_prms *p)
{
	int			fd;
	t_bmp_h		head;
	int			i;
	int			j;
	char		*img_data;

	if ((fd = open(SAVE_FILE_NAME, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1
		&& (p->error = strerror(errno)))
		return (0);
	put_msg(SAVING_MSG);
	save_init_header(p, &head);
	save_headers(fd, &head);
	i = p->res.y;
	img_data = (char *)p->img_adr;
	while (--i >= 0)
	{
		j = -1;
		while (++j < p->res.x)
			write(fd, &(img_data[i * p->line_size + j * 4]), 3);
	}
	if (close(fd) == -1 && (p->error = strerror(errno)))
		return (0);
	mlx_destroy_image(p->mlx, p->image);
	put_msg(SAVING_OK_MSG);
	return (1);
}
