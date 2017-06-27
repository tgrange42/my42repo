/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:07:59 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/27 17:54:37 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_list(t_env **env)
{
	t_env	*tmp;
	t_env	*tmp2;

	tmp = *env;
	tmp2 = tmp;
	while (tmp)
	{
		tmp2 = tmp->next;
		ft_strdel(&tmp->name);
		ft_strdel(&tmp->content);
		free(tmp);
		tmp = tmp2;
	}
}

void	exit_ms(t_env **env)
{
	delete_list(env);
	exit(1);
}
