/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:49:54 by tgrange           #+#    #+#             */
/*   Updated: 2017/05/23 17:26:49 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define USAGE 1

void	exit_error(int type_of_error, char wrong_flag)
{
	if (type_of_error == USAGE)
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(wrong_flag);
		ft_putendl("\nusage: ls [-RUalprt1] [file ...]");
		exit(1);
	}
}

void	write_error(char *name_folder, char *error)
{
	ft_putstr("ls: ");
	ft_putstr(name_folder);
	ft_putendl(error);
}

void	not_file(char **name, int nb)
{
	int		i;

	i = 0;
	while (name[i])
	{
		ft_putstr("ls: ");
		ft_putstr(name[i++]);
		ft_putendl(": No such file or directory");
	}
	(void)nb;
	// clean_tabn(&name, nb);
}
