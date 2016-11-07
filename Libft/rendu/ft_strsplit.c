/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:38:22 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/07 10:57:03 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		l;

	l = 0;
	j = 0;
	i = 0;
	if (!(res = (char **)malloc(sizeof(res) * ft_countchar(s, c))))
		return (NULL);
	ft_putnbr(ft_strlen(s));
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			if (!(res[j] = (char *)malloc(sizeof(res[j]) * ft_strlento(s, c, i))))
				return (NULL);
			ft_putnbr(ft_strlen(s));
			while (s[i] != c && s[i])
			{
				res[j][l] = s[i];
				i++;
				l++;
			}
			res[j][l] = '\0';
			l = 0;
			j++;
		}
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
