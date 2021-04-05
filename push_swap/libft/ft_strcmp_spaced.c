/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_spaced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:37:30 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 19:48:45 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp_spaced(const char *s1_spaced, const char *s2)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s2[j] && s2[j] != ' ' && s1_spaced[i] && s1_spaced[i] == ' ')
		i++;
	while (s1_spaced[i] && s2[j] && s1_spaced[i] == s2[j])
	{
		i++;
		j++;
	}
	while (s1_spaced[i] && s1_spaced[i] == ' ')
		i++;
	if (!s1_spaced[i] && !s2[j])
		return (0);
	else
		return (1);
}
