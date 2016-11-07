/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlento.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:49:33 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/07 09:08:08 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlento(const char *s, char c, int n)
{
	int		i;

	i = 0;
	while (s[n] != '\0' && s[n] != c)
	{
		n++;
		i++;
	}
	return (i);
}
