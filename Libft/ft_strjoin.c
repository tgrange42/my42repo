/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:44:50 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/19 13:12:56 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoinv(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	j = ft_strlen(s1);
	i = ft_strlen(s2);
	if (!(dst = (char *)ft_memalloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dst[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		dst[j] = s2[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	if (!(s2) || !(s1))
		return (NULL);
	return (ft_strjoinv(s1, s2));
}
