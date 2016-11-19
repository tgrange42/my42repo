/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:55:20 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/14 09:44:42 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	buf;

	i = 0;
	buf = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == buf)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == buf)
		return ((char *)&s[i]);
	return (NULL);
}
