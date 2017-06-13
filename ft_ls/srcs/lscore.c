/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lscore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:39:04 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/12 15:55:36 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_info	*get_files_names(char *path, t_flags flags, char *name)
{
	DIR				*stream;
	struct dirent	*list;
	t_info			*ret;

	ret = NULL;
	errno = 0;
	stream = opendir(path);
	if (errno)
	{
		write_error(name, strerror(errno));
		return (NULL);
	}
	while ((list = readdir(stream)) != NULL)
	{
		if (list->d_name[0] != '.' || flags.a_flag)
			create_t_info(list->d_name, get_path(path, list->d_name),
				flags, &ret);
	}
	closedir(stream);
	return (ret);
}

void	recursive_ls(t_info **infos, t_flags flags)
{
	t_info	*tmp;
	t_info	*tmp2;

	tmp = *infos;
	while (tmp)
	{
		if (tmp->name[0] && tmp->type == 'd' && ft_strcmp(tmp->name, "..") &&
			ft_strcmp(tmp->name, "."))
		{
			ft_putbegl(tmp->path);
			ft_putendl(":");
			ft_opendir(flags, tmp->path, NULL, tmp->name);
		}
		tmp2 = tmp->next;
		rm_t_info(tmp);
		tmp = tmp2;
	}
}

void	ft_opendir(t_flags flags, char *name, t_info *infos, char *pure_name)
{
	if (!(infos = get_files_names(name, flags, pure_name)))
		return ;
	if (flags.r_flag)
		rev_list(&infos);
	if (flags.l_flag)
		collect_infos(&infos);
	print_dir(flags, &infos, 1);
	if (flags.grand_r_flag)
		recursive_ls(&infos, flags);
	clean_lst(&infos);
}

void	files_not_repo(char **names, t_flags flags)
{
	int			i;
	t_info		*files;

	if (!names[0])
		return ;
	files = NULL;
	i = 0;
	while (names[i])
	{
		create_t_info(names[i], names[i], flags, &files);
		i++;
	}
	if (flags.r_flag)
		rev_list(&files);
	if (flags.l_flag)
		collect_infos(&files);
	print_dir(flags, &files, 0);
	clean_lst(&files);
}

void	get_multiple_arg(char ***argv, t_flags flags)
{
	int		i;
	int		l;
	t_info	*lst;

	i = 0;
	l = ft_tablen(argv[1]);
	not_file(argv[2]);
	files_not_repo(argv[0], flags);
	lst = tab_to_t_info(argv[1], flags);
	while (lst)
	{
		if (l > 1 || argv[0][0] || argv[2][0])
		{
			if (i > 0 || argv[0][0])
				ft_putendl("");
			ft_putstr(lst->name);
			ft_putendl(":");
		}
		ft_opendir(flags, lst->name, NULL, lst->name);
		lst = lst->next;
		i++;
	}
}
