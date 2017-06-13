/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:49:54 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/08 14:54:38 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#define USAGE 1

void	exit_error(int type_of_error, char wrong_flag)
{
	if (type_of_error == USAGE)
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putchar_fd(wrong_flag, 2);
		ft_putendl_fd("\nusage: ls [-RUalprt1] [file ...]", 2);
		exit(1);
	}
}

void	write_error(char *name_folder, char *error)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(name_folder, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
}

void	not_file(char **name)
{
	int		i;

	i = 0;
	while (name[i])
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(name[i++], 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
}
