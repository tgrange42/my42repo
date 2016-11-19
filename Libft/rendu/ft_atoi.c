/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:53:39 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/19 11:50:24 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		res;
	int		i;
	int		neg;

	neg = 0;
	i = 0;
	res = 0;
	while (str[i] < 33)
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0' && str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-res);
	return (res);
}
