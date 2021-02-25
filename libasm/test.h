/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:24:56 by tcider            #+#    #+#             */
/*   Updated: 2021/02/02 10:30:01 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include "libasm_bonus.h"

# define BUF_SIZE 100

void		test_atoi_base(void);
t_list		*test_list1(char **str);
void		test_list2(t_list **list, char **str);

#endif
