/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:59:08 by tgrange           #+#    #+#             */
/*   Updated: 2017/03/17 17:28:51 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	get_multiple_flags(char **argv, t_flags *stock)
{
	int		i;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		get_flags(stock, argv[i]);
		i++;
	}
}

void	initialize_struct_flags(t_flags *flags)
{
	flags->R_flag = 0;
	flags->a_flag = 0;
	flags->l_flag = 0;
	flags->r_flag = 0;
	flags->t_flag = 0;
}

void	get_flags(t_flags *stock, char *flags)
{
	int		i;

	i = 1;
	while (flags[i])
	{
		if (ft_strchr("Ralrt", (int)flags[i]) == NULL)
			exit_error(1, flags[i]);
		if (flags[i] == 'R')
			stock->R_flag = 1;
		if (flags[i] == 'a')
			stock->a_flag = 1;
		if (flags[i] == 'l')
			stock->l_flag = 1;
		if (flags[i] == 'r')
			stock->r_flag = 1;
		if (flags[i] == 't')
			stock->t_flag = 1;
		i++;
	}
}
