/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:25:33 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/09 18:11:45 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_base_v(int nb, int base, char *ret)
{
	int		neg;
	int		i;

	i = 0;
	neg = 0;
	if (base == 10 && nb < 0)
		neg = 1;
	if (nb > 0)
		nb *= -1;
	while (nb)
	{
		if (base > 10 && -(nb % base) > 9)
			ret[i++] = -(nb % base) - 10 + 'a';
		else
			ret[i++] = -(nb % base) + '0';
		nb /= base;
	}
	if (neg)
		ret[i++] = '-';
	ret[i] = '\0';
	return (ret);
}

char			*ft_itoa_base(int nb, int base)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * 32)))
		return (NULL);
	if (base < 2)
		return (ft_revstr(ft_itoa_base_v(nb, 2, ret), 1));
	if (base > 16)
		return (ft_revstr(ft_itoa_base_v(nb, 16, ret), 1));
	if (nb == 0)
	{
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	return (ft_revstr(ft_itoa_base_v(nb, base, ret), 1));
}
