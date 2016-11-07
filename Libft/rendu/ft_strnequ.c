/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:37:14 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/07 17:41:43 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}

int		main(int nbarg, char **arg)
{
	(void)nbarg;
	ft_putnbr(ft_strnequ(arg[1], arg[2], (size_t)ft_atoi(arg[3])));
	return (0);
}
