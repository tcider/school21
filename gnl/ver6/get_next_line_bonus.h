/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:58:36 by tcider            #+#    #+#             */
/*   Updated: 2020/11/08 12:59:16 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define FD_LIM 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct		s_buf
{
	char			*data;
	int				size;
}					t_buf;

typedef struct		s_lst
{
	char			*data;
	int				size;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_headlst
{
	t_lst			*head;
	t_lst			*tail;
	int				size;
}					t_headlst;

int					get_next_line(int fd, char **line);
t_lst				*to_create_elem(char *str, int size);
t_headlst			*to_lst_makebuf(t_buf **buf);
t_headlst			*to_lst_addbuf(t_headlst *head, char *str, int size);
char				*to_lst_joinbuf(t_headlst *head);
void				to_lst_clear(t_headlst **head, t_buf **buf, int ret);

#endif
