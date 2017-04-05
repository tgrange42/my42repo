/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:49:54 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/04 15:47:08 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define USAGE 1
#define DIRERROR 2

void	exit_error(int type_of_error, char wrong_flag)
{
	if (type_of_error == USAGE)
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(wrong_flag);
		ft_putendl("\nusage: ls [-Ralrt][file ...]");
		exit(1);
	}
}
