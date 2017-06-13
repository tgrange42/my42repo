/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:23:55 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/03 14:16:59 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenword(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		nbwd;

	i = 0;
	nbwd = ft_countav(s, c);
	if (!s)
		return (NULL);
	if (!(res = (char **)ft_memalloc(sizeof(*res) * (nbwd + 1))))
		return (NULL);
	while (nbwd--)
	{
		while (*s == c && *s)
			s++;
		res[i] = ft_strsub(s, 0, ft_lenword(s, c));
		if (res[i] == NULL)
		{
			ft_memdel((void **)res);
			return (NULL);
		}
		s += ft_lenword(s, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}
