/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:01:14 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/14 17:20:11 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <sys/ioctl.h>

char	*get_dir(char *path);
void	print_dir_prompt(void);
char	**cpytab(char **tab, int size);
char	*get_path(char *actual_path, char *dir_name);
void	clean_minishell(void);

char	*get_dir(char *path)
{
	char	*tmp;

	tmp = ft_strrchr(path, '/');
	return (&tmp[1]);
}

void	print_dir_prompt(void)
{
	ft_putstr(get_dir(getcwd(NULL, 0)));
	ft_putstr("> ");
}

char	**cpytab(char **tab, int size)
{
	char	**ret;
	int		i;

	i = 0;
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * ((size_t)size + 1))))
		return (NULL);
	while (i < size)
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	return (ret);
}

char	*get_path(char *actual_path, char *dir_name)
{
	char	*path;
	size_t	len;

	len = ft_strlen(actual_path) + ft_strlen(dir_name) + 2;
	if (!(path = (char *)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	path = ft_strcpy(path, actual_path);
	if (!(actual_path[0] == '/' && ft_strlen(actual_path) == 1))
		path[ft_strlen(actual_path)] = '/';
	path = ft_strcat(path, dir_name);
	return (path);
}

int		main(int ac, char **av)
{
	char			*buf;
	char			**args;
	pid_t			father;
	int				lol;

	lol = 2	;
	(void)ac;
	(void)av;
	print_dir_prompt();
	while (get_next_line(0, &buf))
	{
		args = ft_strsplit(buf, ' ');
		if (!ft_strcmp("shrug", buf))
			ft_putendl("¯\\_(ツ)_/¯");
		else
		{
			father = fork();
			if (father > 0)
				wait(&lol);
			if (!father)
			{
				args[0] = get_path("/bin", args[0]);
				execve(args[0], args, NULL);
			}
			print_dir_prompt();	
		}
	}
	return (0);
}
