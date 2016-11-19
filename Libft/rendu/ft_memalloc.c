/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:43:06 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/16 11:16:04 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*area;
	int		i;

	i = 0;
	area = NULL;
	if (!(area = (char *)malloc(sizeof(area) * size)))
		return (NULL);
	while (area[i])
	{
		area[i] = '\0';
		i++;
	}
	return ((void *)area);
}
