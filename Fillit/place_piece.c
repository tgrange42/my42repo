
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 03:31:14 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/09 01:14:21 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"	

void	place_this_shit(char *table, int *pos, int i, int letter)
{
	table[i] = (char)('A' + letter);
	table[i + pos[1] + get_line(pos[0], pos[1]) * (ft_strlento(table, '\n') - 4)] = (char)
	('A' + letter);
	table[i + pos[2] + get_line(pos[0], pos[2]) * (ft_strlento(table, '\n') - 4)] = (char)
	('A' + letter);
	table[i + pos[3] + get_line(pos[0], pos[3]) * (ft_strlento(table, '\n') - 4)] = (char)
	('A' + letter);
}

void	debug(char *table, char letter)
{
	int		i;

	i = 0;
	while (table[i])
	{
		if (table[i] == letter || table[i] == '\n')
			ft_putchar(table[i]);
		else
			ft_putnbr(i % 10);
		i++;
	}
}

char	*clean_table(char *table, char letter)
{
	int		i;

	i = 0;
	while (table[i])
	{
		if (table[i] >= letter + 'A')
		{
			table[i] = '.';
		}
		i++;
	}
	return (table);
}

int		get_actual_pos(char *table, int letter)
{
	int		i;

	i = 0;
	while (table[i] != (char)(letter + 'A'))
		i++;
	return (i);
}

int		get_line(int i, int pos)
{
	char	piece[21];
	int		u;
	int		j;

	j = i;
	u = 0;
	piece[20] = '\0';
	ft_memset((void *)piece, '.', 20);
	piece[4] = '\n';
	piece[9] = '\n';
	piece[14] = '\n';
	while (j - i <= pos)
	{
		if (piece[j] == '\n')
			u++;
		j++;
	}
	return (u);
}
