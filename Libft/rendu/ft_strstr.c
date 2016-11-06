/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:44:23 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/06 15:44:25 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstrv(const char *big, const char *little)
{
	size_t		beacon;
	size_t		i;
	size_t		j;
	char		*buf;

	beacon = 0;
	j = 0;
	i = 0;
	buf = (char *)big;
	while (beacon < ft_strlen(big))
	{
		while (big[i] != '\0')
		{
			if (big[i] == little[j])
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

char	*ft_strstr(const char *big, const char *little)
{
	char	*res;

	res = (char *)big;
	if (ft_strcmp(little, "") != 0)
		return (ft_strstrv(big, little));
	return (res);
}
