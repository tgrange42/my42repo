/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:02:00 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/09 05:04:27 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putendl_fd("error", 1);
}

int		verif_options(int nbarg)
{
	if (nbarg == 1 || nbarg > 2)
	{
		error();
		return (0);
	}
	else
		return (1);
}

void	put_it(char **lol)
{
	int		i;

	i = 0;
	while (lol[i])
		ft_putendl(lol[i++]);
}

void	lulz(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '-')
		ft_putchar(s[i++]);
}

void	t_free(void **t)
{
	int		i;

	i = 0;
	while (t[i])
			free(t[i++]);
	free(t[i]);
	free(t);	
}

void	exit_fillit(char *table, int **pos)
{
	t_free((void **)pos);
	lulz(table);
	free(table);
}

int		main(int nbarg, char **arg)
{
	char	**tetros;

	tetros = NULL;
	if (!verif_options(nbarg))
		return (1);
	if (!(tetros = verif_tetros(arg[1])))
		return (1);
//	put_it(tetros);
	lets_do_this(tetros);
//	t_free(tetros);
	return (0);
}
