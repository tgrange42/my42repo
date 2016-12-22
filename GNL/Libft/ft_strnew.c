/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:58:54 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/16 11:25:55 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!(newstr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		newstr[i] = '\0';
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
