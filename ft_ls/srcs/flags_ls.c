/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:59:08 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/12 15:52:07 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	initialize_struct_flags(t_flags *flags)
{
	flags->grand_c_flag = 0;
	flags->grand_r_flag = 0;
	flags->grand_u_flag = 0;
	flags->a_flag = 0;
	flags->d_flag = 0;
	flags->l_flag = 0;
	flags->p_flag = 0;
	flags->r_flag = 0;
	flags->t_flag = 0;
	flags->one_flag = 0;
}

void	get_flags_2(t_flags *stock, char *flags, int i)
{
	if (flags[i] == 'U')
		stock->grand_u_flag = 1;
	if (flags[i] == '1')
	{
		stock->l_flag = 0;
		stock->one_flag = 1;
	}
	if (flags[i] == 'd')
		stock->d_flag = 1;
	if (flags[i] == 'C')
	{
		stock->one_flag = 0;
		stock->l_flag = 0;
		stock->grand_c_flag = 1;
	}
}

void	get_flags(t_flags *stock, char *flags, int i)
{
	while (flags[++i])
	{
		if (ft_strchr("CRUadlprt1", (int)flags[i]) == NULL)
			exit_error(1, flags[i]);
		if (flags[i] == 'R')
			stock->grand_r_flag = 1;
		if (flags[i] == 'a')
			stock->a_flag = 1;
		if (flags[i] == 'r')
			stock->r_flag = 1;
		if (flags[i] == 't')
			stock->t_flag = 1;
		if (flags[i] == 'p')
			stock->p_flag = 1;
		if (flags[i] == 'l')
		{
			stock->one_flag = 0;
			stock->l_flag = 1;
		}
		get_flags_2(stock, flags, i);
	}
}

void	get_multiple_flags(char **argv, t_flags *stock)
{
	int		i;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		get_flags(stock, argv[i], 0);
		i++;
	}
}
