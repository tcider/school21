/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:39:04 by tcider            #+#    #+#             */
/*   Updated: 2020/11/06 20:02:11 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //FIXME

# define FD_LIM 1024
# define BUF_SIZE 6 //FIXME

typedef struct		s_buf
{
	char			*data;
	int				size;
	int				nl;
}					t_buf;

int		get_next_line(int fd, char **line);
int		find_new_line(char *str, int ret);
void	free_list_line(t_buf **blst);
void	split_nl_line(t_buf *blst, char *s1, char *s2);
int		split_buf_line(t_buf **blst, char **line);
int		add_buf_line(t_buf **blst, char *buf, int ret);

#endif
