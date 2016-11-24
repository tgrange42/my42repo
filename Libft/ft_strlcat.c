/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:40:27 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/19 11:10:08 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		endofdst;

	endofdst = 0;
	i = 0;
	while (dst[i] && i < size)
		i++;
	endofdst = i;
	while (src[i - endofdst] && i < size - 1)
	{
		dst[i] = src[i - endofdst];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (endofdst + ft_strlen(src));
}
