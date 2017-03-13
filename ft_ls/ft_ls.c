/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:40:54 by tgrange           #+#    #+#             */
/*   Updated: 2017/03/10 17:12:17 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	initialize_struct_flags(t_flags *flags)
{
	flags->R_flag = 0;
	flags->a_flag = 0;
	flags->l_flag = 0;
	flags->r_flag = 0;
	flags->t_flag = 0;
}

int		main(int argc, char **argv)
{
	t_flags		flags;

	initialize_struct_flags(&flags);
	get_multiple_flags(argv, &flags);
	ft_putstr("R_flag = ");
	ft_putnbr(flags.R_flag);
	ft_putstr("\na_flag = ");
	ft_putnbr(flags.a_flag);
	ft_putstr("\nl_flag = ");
	ft_putnbr(flags.l_flag);
	ft_putstr("\nr_flag = ");
	ft_putnbr(flags.r_flag);
	ft_putstr("\nt_flag = ");
	ft_putnbr(flags.t_flag);
	return (0);
}
