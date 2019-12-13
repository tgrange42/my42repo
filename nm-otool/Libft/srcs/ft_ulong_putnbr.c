/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulong_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:54:40 by tgrange           #+#    #+#             */
/*   Updated: 2019/04/20 17:02:43 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ulong_putnbr(unsigned long n)
{
	unsigned long	x;

	x = 10;
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
