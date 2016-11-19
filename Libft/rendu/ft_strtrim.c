/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:13:56 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/17 10:55:03 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_endspaces(const char *s)
{
	int		i;
	int		x;

	x = 0;
	i = ft_strlen(s) - 1;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
	{
		i--;
		x++;
	}
	return (x);
}

static int		ft_begspaces(const char *s)
{
	int		i;

	i = 0;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		i++;
	return (i);
}

static char		*ft_strtrimv(const char *s)
{
	char	*dst;
	int		end;
	int		beg;
	int		i;

	i = 0;
	beg = ft_begspaces(s);
	end = ft_endspaces(s);
	if (!(dst = (char *)malloc(sizeof(char) * \
					((int)ft_strlen(s) - (beg + end - 1)))))
		return (NULL);
	while (beg < (int)ft_strlen(s) - end)
	{
		dst[i] = s[beg];
		beg++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char			*ft_strtrim(const char *s)
{
	int		i;

	i = 0;
	if (!(s))
		return (NULL);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (ft_strtrimv(s));
		i++;
	}
	return ("");
}
