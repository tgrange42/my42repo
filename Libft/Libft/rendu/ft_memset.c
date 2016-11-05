/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:05:58 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/04 15:02:44 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*buf;

	buf = (char *)b;
	i = 0;
	while (i < len)
	{
		buf[i] = (unsigned char)c;
		i++;
	}
	b = (void *)buf;
	return (b);
}
