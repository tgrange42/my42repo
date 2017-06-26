/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:22:35 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/26 18:11:40 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*get_content(t_env **begin, char *name)
{
	t_env	*env;

	env = *begin;
	while (env)
	{
		if (ft_strequ(name, env->name))
			return (env->content);
		env = env->next;
	}
	return (NULL);
}

t_env		*get_env(char **environ)
{
	t_env	*ret;
	int		i;
	char	**tmp;

	i = 0;
	ret = NULL;
	while (environ[i])
	{
		tmp = ft_strsplit(environ[i++], '=');
		create_t_env(&ret, tmp[0], tmp[1]);
		del_tabstr(&tmp);
	}
	return (ret);
}
