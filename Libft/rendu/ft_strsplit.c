/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:38:22 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/06 17:03:09 by tgrange          ###   ########.fr       */
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
	while (s[i] != '\0')
	{
		ft_putchar('t');
		while (s[i] == c)
		{
			ft_putchar('e');
			i++;
		}
		if (s[i] != c && s[i] != '\0')
		{
			ft_putchar('i');
			while (s[i] != c && s[i] != '\0')
			{
				ft_putchar('o');
				if (!(res[j] = (char *)malloc(sizeof(char) * ft_strlento(s, c, i))))
					return (NULL);
				ft_putchar('o');
				res[j][l] = s[i];
				i++;
				l++;
			}
			res[j][l] = '\0';
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
		ft_putchar('t');
		ft_putstr(res[i]);
		i++;
	}
	return (0);
}
