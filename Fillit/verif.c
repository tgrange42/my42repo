/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:28:03 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/09 05:06:05 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verif_one(char *tetros)
{
	int		i;
	int		p;
	int		d;
	int		n;

	i = 0;
	p = 0;
	d = 0;
	n = 0;
	while (tetros[i])
	{
		if (tetros[i] == '#')
			d++;
		if (tetros[i] == '\n')
			n++;
		if (tetros[i++] == '.')
			p++;
	}
	if (n == 4 && p == 12 && d == 4)
		return (1);
	free(tetros);
	return (0);
}

int		verif_chars(char **tetros)
{
	int		i;

	i = 0;
	while (tetros[i])
		if (!verif_one(tetros[i++]))
			return (0);
	return (1);
}

char	**verif_tetros(char *file_name)
{
	char	**tetros;

	tetros = get_tetrominos(file_name);
	if (tetros[0] == NULL)
	{
		error();
		return (NULL);
	}
	if (!verif_chars(tetros))
	{
//		t_free(tetros);
		error();
		return (NULL);
	}
	if (!tetro_or_not_tetro(tetros))
	{
		t_free((void **)tetros);
		error();
		return (NULL);
	}
	return (tetros);
}
