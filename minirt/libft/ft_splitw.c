/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:59:55 by tcider            #+#    #+#             */
/*   Updated: 2021/01/03 19:03:40 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nwords(const char *tmp)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (tmp[i])
	{
		if (tmp[i] != ' ' && tmp[i] != '\t')
		{
			sum++;
			while (tmp[i] && tmp[i] != ' ' && tmp[i] != '\t')
				i++;
		}
		else
			i++;
	}
	return (sum);
}

static char		*ft_getchar(const char *str)
{
	char	*res;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	if (!(res = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (k < i)
	{
		res[k] = str[k];
		k++;
	}
	res[k] = '\0';
	return (res);
}

char			**ft_splitw(char const *s, int *nwords)
{
	int		i;
	int		k;
	char	**res;

	if (s)
		*nwords = ft_nwords(s);
	if (!s || !(res = (char**)malloc(sizeof(char*) * (*nwords + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (s[i])
		{
			res[k] = ft_getchar(&s[i]);
			k++;
		}
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
	}
	res[k] = NULL;
	return (res);
}
