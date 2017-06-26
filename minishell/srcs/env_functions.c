/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:53:24 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/26 16:56:57 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	display_env(t_env **begin)
{
	t_env	*env;

	env = *begin;
	while (env)
	{
		ft_putstr(env->name);
		ft_putchar('=');
		ft_putendl(env->content);
		env = env->next;
	}
}
