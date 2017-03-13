/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 06:38:50 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/19 11:56:22 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*t1;
	const char	*t2;

	i = 0;
	t1 = (char *)dst;
	t2 = (const char *)src;
	if (!n)
		return (dst);
	while (i < n)
	{
		t1[i] = t2[i];
		i++;
	}
	return (dst);
}
