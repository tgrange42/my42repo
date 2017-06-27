/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:21:18 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/27 17:54:33 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		goto_func(char **args, t_env *env)
{
	if (ft_strequ("env", args[0]))
	{
		display_env(&env);
		return (1);
	}
	else if (ft_strequ("echo", args[0]))
	{
		echo(&args[1], env);
		return (1);
	}
	else if (ft_strequ("exit", args[0]))
		exit_ms(&env);
	else if (ft_strequ("cd", args[0]))
	{
		cd(&env, &args[1]);
		return (1);
	}
	else if (ft_strequ("pwd", args[0]))
	{
		pwd();
		return (1);
	}
	return (0);
}

void	mini_core(t_env *env)
{
	char	*buf;
	char	**args;

	buf = NULL;
	while (1)
	{
		display_prompt(env);
		get_next_line(0, &buf);
		args = ft_strsplit(buf, ' ');
		if (!(goto_func(args, env)))
			ft_putendl(buf);
		del_tabstr(&args);
		ft_strdel(&buf);
	}
}
