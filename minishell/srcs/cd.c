/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:41:04 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/27 17:54:36 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	change_dir(t_env **begin, char **args, int p)
{
	if (p)
	{
		p = 1;
	}
	
	chdir(args[p]);
	add_or_change(begin, "OLDPWD", get_content(begin, "PWD"));
	force_pwd(begin);
}

void	cd(t_env **begin, char **args)
{
	int		p;

	p = 0;
	if (ft_strequ("-P", args[0]))
		p = 1;
	change_dir(begin, args, p);
}
