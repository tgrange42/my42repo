/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:53:55 by tgrange           #+#    #+#             */
/*   Updated: 2019/11/04 15:19:03 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_uint_putnbr(size_t n)
{
	size_t	x;

	x = 1;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (n / (x * 10) != 0)
		x *= 10;
	while (x)
	{
		ft_putchar(n / x + '0');
		n %= x;
		x /= 10;
	}
}
