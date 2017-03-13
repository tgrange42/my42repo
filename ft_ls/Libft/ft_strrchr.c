/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:18:50 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/05 15:27:17 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	buf;

	i = ft_strlen(s);
	buf = (char)c;
	while (i >= 0)
	{
		if (s[i] == buf)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == buf)
		return ((char *)&s[i]);
	return (NULL);
}
