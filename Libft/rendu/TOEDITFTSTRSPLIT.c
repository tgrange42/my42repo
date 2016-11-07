/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:38:22 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/07 14:46:42 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countit(const char *str, char c)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			x++;
			while (str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (x);
}

char	*ft_strcpyto(char const *str, char *dst, char c, int i)
{
	int		l;

	l = 0;
	if (!(dst = (char *)malloc(sizeof(char) * ft_strlento(str, c, i))))
		return (NULL);
	while (str[i] && str[i] != c)
	{
		dst[l] = str[i];
		i++;
		l++;
	}
	return (dst);
}

char	**ft_strsplitv(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(res = (char **)malloc(sizeof(char) * ft_countit(s, c))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			res[j] = ft_strcpyto(s, res[j], c, i);
			while (s[i] != c)
				i++;
			j++;
		}
		i++;
	}
	return (res);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;

	res = ft_strsplitv(s, c);
	i = ft_countit(s, c);
	while (res[i])
	{
		res[i] = NULL;
		i++;
	}
	return (res);
}

int		main(int nbarg, char **arg)
{
	char	**res;
	int		i;

	(void)nbarg;
	i = 0;
	res = ft_strsplit(arg[1], arg[2][0]);
	while (res[i])
	{
		ft_putstr(res[i]);
		ft_putchar(' ');
		i++;
	}
	free(res);
	return (0);
}
