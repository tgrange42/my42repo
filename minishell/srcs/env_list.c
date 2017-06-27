/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:47:16 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/27 17:54:34 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	equal_equal(t_env **t1, t_env **t2, t_env **s1, t_env **s2)
{
	*t1 = *t2;
	*s1 = *s2;
}

void	push_alpha(t_env **begin, t_env *new)
{
	t_env	*tmp;

	if (!*begin)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	delete_t_env(t_env **begin, char *variable_to_delete)
{
	t_env	*env;
	t_env	*tmp;

	if (!get_content(begin, variable_to_delete))
		return ;
	env = *begin;
	while (env && env->next && ft_strcmp(variable_to_delete, env->next->name))
		env = env->next;
	tmp = env->next->next;
	ft_strdel(&env->next->name);
	ft_strdel(&env->next->content);
	free(env->next);
	env->next = tmp;
}

void	add_or_change(t_env **begin, char *name, char *content)
{
	t_env	*env;

	if (!get_content(begin, name))
		create_t_env(begin, name, content);
	else
	{
		env = *begin;
		while (ft_strcmp(name, env->name))
			env = env->next;
		ft_strdel(&env->content);
		env->content = ft_strdup(content);
	}
}

void	create_t_env(t_env **begin, char *name, char *content)
{
	t_env	*tmp;

	if (!(tmp = (t_env *)ft_memalloc(sizeof(t_env))))
		return ;
	tmp->name = ft_strdup(name);
	tmp->content = ft_strdup(content);
	tmp->next = NULL;
	push_alpha(begin, tmp);
}
