/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:40:54 by tgrange           #+#    #+#             */
/*   Updated: 2017/03/17 17:28:42 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		main(int argc, char **argv)
{
	t_flags		flags;

	(void)argc;
	initialize_struct_flags(&flags);
	get_multiple_flags(argv, &flags);
	get_multiple_arg(argv, flags);
	return (0);
}
