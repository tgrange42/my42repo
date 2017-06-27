/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:39:35 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/27 17:54:35 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>
# include <limits.h>

# include "../Libft/libft.h"

/*
**	structs
*/

typedef	struct		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

/*
**	cd.c
*/

void				cd(t_env **begin, char **args);

/*
**	echo.c
*/

void				echo2(char *str, t_env *env);
void				echo(char **str, t_env *env);

/*
**	env.c
*/

void				force_pwd(t_env **begin);
char				*get_content(t_env **begin, char *name);
t_env				*get_env(char **environ);

/*
**	env_functions.c
*/

void				display_env(t_env **env);

/*
**	env_list.c
*/

void				delete_t_env(t_env **begin, char *variable_to_delete);
void				add_or_change(t_env **begin, char *name, char *content);
void				equal_equal(t_env **t1, t_env **t2, t_env **s1, t_env **s2);
void				push_alpha(t_env **begin, t_env *new);
void				create_t_env(t_env **begin, char *name, char *content);

/*
**	exit_ms.c
*/

void				delete_list(t_env **env);
void				exit_ms(t_env **env);

/*
**	minishell.c
*/

/*
**	mini_core.c
*/

int					goto_func(char **args, t_env *env);
void				mini_core(t_env *begin);

/*
**	pwd.c
*/

void				pwd(void);

/*
**	tools.c
*/

void				display_prompt(t_env *env);
void				del_tabstr(char ***str);

#endif
