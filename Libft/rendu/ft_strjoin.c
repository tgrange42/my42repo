/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:44:50 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/07 15:50:16 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	j = ft_strlen(s1);
	i = ft_strlen(s2);
	if (!(dst = (char *)malloc(sizeof(char) * (s1 + s2))))
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

int		main(int nbarg, char **arg)
{
	(void)nbarg;
	ft_putstr
}
