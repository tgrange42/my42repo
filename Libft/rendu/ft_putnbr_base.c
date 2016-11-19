/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:12:57 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/16 13:12:58 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nb, char *base)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if ((size_t)nb >= ft_strlen(base))
	{
		ft_putnbr_base((size_t)nb / ft_strlen(base), base);
		ft_putnbr_base((size_t)nb % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nb]);
}
