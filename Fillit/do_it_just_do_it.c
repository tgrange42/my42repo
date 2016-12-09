/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_just_do_it.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:13:35 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/10 00:04:15 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_this_shit(int *fdp)
{
	free(fdp);
	fdp = NULL;
}

int		*get_pos(char *t)
{
	int		*pos;
	int		i;
	int		j;
	int		x;

	if (!(pos = (int *)malloc(sizeof(int) * 4)))
		return (0);
	x = 1;
	j = 1;
	i = 0;
	while (t[i] != '#')
		i++;
	pos[0] = i;
	i++;
	while (x < 4)
	{
		if (t[i] == '#')
			pos[x++] = j;
		i++;
		j++;
	}
	return (pos);
}

char	*do_a_table(char *table, int size)
{
	int		i;

	i = 0;
	if (!(table = (char *)malloc(sizeof(char) * (size_t)((size + 1) *
		size + (size + 1) * 2 + 1))))
		error();
	ft_memset((void *)table, '.', (size_t)((size + 1) * size));
	while (i <= (size + 1) * size)
	{
		if ((i + 1) % (size + 1) == 0)
			table[i] = '\n';
		i++;
	}
	table[(size + 1) * size] = '-';
	while (i < (size + 1) * size + (size + 1) * 2 + 1)
		table[i++] = '-';
	table[i] = '\0';
	return (table);
}

int		this_can_enter(char *table, int *pos, int i)
{
	if (table[i] == '.' &&
		table[i + pos[1] + get_line(pos[0], pos[1]) * (ft_strlento(table, '\n') - 4)] == '.' &&
		table[i + pos[2] + get_line(pos[0], pos[2]) * (ft_strlento(table, '\n') - 4)] == '.' &&
		table[i + pos[3] + get_line(pos[0], pos[3]) * (ft_strlento(table, '\n') - 4)] == '.')
		return (1);
	return (0);
}

#include <stdio.h>

int		roger_that(int **pos, int posi, char *table, int letter)
{
	// ft_putendl("table=");
	// ft_putendl(table);
	// ft_putstr("posi = ");
	// ft_putnbr(posi);
	// ft_putstr("\nletter = ");
	// ft_putchar((char)letter + 'A');
	// ft_putchar('\n');
	// printf("posi = %i\nletter = %i\n", posi, letter);
	if (table[posi] == '.' && this_can_enter(table, pos[letter], posi))
	{
		place_this_shit(table, pos[letter], posi, letter);
		if (!(pos[letter + 1]))
		{
			exit_fillit(table, pos);
			exit(1);
		}
		roger_that(pos, 0, table, letter + 1);
	}
	else
	{
		if (letter == 0 && table[posi] == '-')
		{
			table = do_a_table(table, ft_strlento(table, '\n') + 1);
			roger_that(pos, 0, table, 0);
		}
		else if (table[posi] == '-')
			roger_that(pos, get_actual_pos(table, letter - 1) + 1,
				clean_table(table, (char)letter - 1), letter - 1);
		roger_that(pos, posi + 1, table, letter);
	}
	return (0);
}


void	lets_do_this(char **tetros)
{
	char	*table;
	int 	min;
	int		**pos;
	int		i;

	i = 0;
	min = ft_sqrt(ft_getnbtab((void **)tetros) * 4);
	if (!(pos = (int **)malloc(sizeof(pos) *
		(size_t)ft_getnbtab((void *)tetros))))
		return ;
	while (i < ft_getnbtab((void **)tetros))
	{
		pos[i] = get_pos(tetros[i]);
		i++;
	}
	pos[i] = NULL;
	table = ft_strdup("LOLYFAUTMALOK");
	table = do_a_table(table, min);
	t_free((void **)tetros);
	roger_that(pos, 0, table, 0);
}

// int		roger_that(char **tetros, int posi, char *table, int letter)
// {
// 	int		*pos;

// 	pos = get_pos(tetros[letter]);
// 	// ft_putendl("------------");
// 	// ft_putendl(table);
// 	// ft_putstr("posi = ");
// 	// ft_putnbr(posi);
// 	// ft_putchar('\n');
// 	// ft_putstr("letter = ");
// 	// ft_putchar((char)letter + 'A');
// 	// ft_putchar('\n');
// 	// ft_putendl("------------");
// 	// ft_putchar((char)letter + 'A');
// 	// ft_putchar('\n');
// 	if (this_can_enter(table, pos, posi))
// 	{
// 		// ft_putstr("this letter can enter = ");
// 		// ft_putchar((char)letter + 'A');
// 		// ft_putchar('\n');
// 		place_this_shit(table, pos, posi, letter);
// 		if (!(tetros[letter + 1]))
// 		{
// 			exit_fillit(table, tetros);
// 			exit(1);
// 		}
// 		roger_that(tetros, 0, table, letter + 1);
// 	}
// 	else
// 	{
// 		if (letter == 0 && table[posi] == '-')
// 		{
// 			table = do_a_table(table, ft_strlento(table, '\n') + 1);
// 			roger_that(tetros, 0, table, 0);
// 		}
// 		else if (table[posi] == '-')
// 			roger_that(tetros, get_actual_pos(table, letter - 1) + 1, clean_table(table, (char)letter - 1), letter - 1);
// 		roger_that(tetros, posi + 1, table, letter);
// 	}
// 	return (0);
// }




