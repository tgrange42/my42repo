/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:49:50 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/09 17:42:26 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstrv(char *buf, const char *little, size_t len)
{
	size_t	beacon;
	size_t	i;
	size_t	j;

	beacon = 0;
	i = 0;
	j = 0;
	while (beacon < len + 1)
	{
		while ((i < len - 1 || (j > 0 && i < len) || (ft_strlen(little) == 1 && i < len)) && buf[i] != '\0')
		{
			if (buf[i] == little[j])
				j++;
			else
				j = 0;
			if (little[j] == '\0')
				return (&buf[i + 1 - ft_strlen(little)]);
			i++;
		}
		beacon++;
		i = beacon;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*res;

	res = (char *)big;
	if (ft_strcmp(little, "") != 0)
		return (ft_strnstrv(res, little, len));
	return (res);
}
