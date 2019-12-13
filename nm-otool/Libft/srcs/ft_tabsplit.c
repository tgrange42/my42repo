/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 14:35:25 by tgrange           #+#    #+#             */
/*   Updated: 2017/07/03 14:59:35 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countavspc(const char *str)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			x++;
			while (str[i] != ' ' && str[i] && str[i] != '\t')
				i++;
		}
		else
			i++;
	}
	return (x);
}

static int		ft_lenword(const char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\t' && s[i] != ' ')
		i++;
	return (i);
}

char			**ft_tabsplit(char const *s)
{
	char	**res;
	int		i;
	int		nbwd;

	i = 0;
	nbwd = ft_countavspc(s);
	if (!s || !nbwd)
		return (NULL);
	if (!(res = (char **)ft_memalloc(sizeof(*res) * (nbwd + 1))))
		return (NULL);
	while (nbwd--)
	{
		while ((*s == ' ' || *s == '\t') && *s)
			s++;
		res[i] = ft_strsub(s, 0, ft_lenword(s));
		if (res[i] == NULL)
			return (NULL);
		s += ft_lenword(s);
		i++;
	}
	res[i] = NULL;
	return (res);
}
