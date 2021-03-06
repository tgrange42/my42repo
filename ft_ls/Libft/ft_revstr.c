/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:55:59 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/09 18:11:16 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str, int do_free)
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
	if (do_free)
		free(str);
	return (ret);
}
