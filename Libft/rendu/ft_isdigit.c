/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:39:28 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/04 13:40:17 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isfigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}
