/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countav.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 01:22:02 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/19 11:50:46 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** count words avoiding special characters
*/

int		ft_countav(const char *str, char c)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			x++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (x);
}
