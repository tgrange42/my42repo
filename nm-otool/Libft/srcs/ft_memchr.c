/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 06:57:55 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/14 07:08:51 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*try;

	try = (unsigned char *)s;
	i = 0;
	c = (unsigned char)c;
	while (i < n)
	{
		if (*try == c)
			return ((void *)s);
		i++;
	}
	try = NULL;
	return ((void *)try);
}
