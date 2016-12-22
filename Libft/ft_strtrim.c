/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:13:56 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/10 03:56:54 by tgrange          ###   ########.fr       */
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

static char		*ft_return_null_s(void)
{
	char	*null;

	if (!(null = (char *)malloc(sizeof(null))))
		return (NULL);
	null[0] = '\0';
	return (null);
}

char			*ft_strtrim(const char *s)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	if (!(s))
		return (res);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			res = ft_strtrimv(s);
			return (res);
		}
		i++;
	}
	return (ft_return_null_s());
}
