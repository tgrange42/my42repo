/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:01:00 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/09 16:25:38 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getintlen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoav(char *res, int n, int dix)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		res[i] = '-';
		i++;
	}
	else
		n *= -1;
	while (dix != 0)
	{
		res[i] = -(n / dix) + '0';
		n %= dix;
		dix /= 10;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		dix;

	if (!(res = (char *)malloc(sizeof(char) * (ft_getintlen(n) + 1))))
		return (NULL);
	dix = 1000000000;
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	while (n / dix == 0)
		dix /= 10;
	res = ft_itoav(res, n, dix);
	return (res);
}
