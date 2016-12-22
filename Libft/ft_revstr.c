/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:55:59 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/17 12:41:41 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str)
{
	char	*ret;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	if (!str)
		return (NULL);
	if (!(ret = (char *)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i--)
	{
		ret[j] = str[i];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
