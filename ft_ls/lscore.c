/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lscore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:39:04 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/05 13:03:21 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info	*get_files_names(char *path, t_flags flags)
{
	DIR				*stream;
	struct dirent	*list;
	t_info			*tmp;
	t_info			*ret;

	ret = NULL;
	stream = opendir(path);
	while ((list = readdir(stream)) != NULL)
	{
		if (list->d_name[0] != '.' || flags.a_flag)
		{
			tmp = create_t_info(list->d_name, list->d_type, get_path(path,
				list->d_name));
			pushback_t_info(tmp, &ret);
		}
	}
	closedir(stream);
	return (ret);
}

void	ft_opendir(t_flags flags, char *name)
{
	t_info	*infos;

	infos = get_files_names(name, flags);
	sort_list_alpha(&infos);
	if (flags.t_flag)
		sort_list_time(&infos);
	if (flags.r_flag)
		rev_list(&infos);
	if (flags.l_flag)
		collect_infos(&infos);
	print_dir(flags, &infos);
	if (flags.grand_r_flag)
		while (infos)
		{
			if (infos->type == 'd' && ft_strcmp(infos->name, "..") &&
				ft_strcmp(infos->name, "."))
			{
				ft_putbegl(infos->path);
				ft_putendl(":");
				ft_opendir(flags, infos->path);
			}
			next_rm(&infos);
		}
	clean_t_info(infos, flags);
}

void	files_not_repo(char **names, t_flags flags)
{
	int			i;
	t_info		*files;
	t_info		*tmp;

	files = NULL;
	i = 0;
	while (names[i])
	{
		tmp = create_t_info(names[i++], 0, ".");
		pushback_t_info(tmp, &files);
	}
	if (flags.t_flag)
		sort_list_time(&files);
	if (flags.r_flag)
		rev_list(&files);
	if (flags.l_flag)
		collect_infos(&files);
	print_dir(flags, &files);
}

void	not_file(char **name)
{
	int		i;

	i = 0;
	while (name[i])
	{
		ft_putstr("ls: ");
		ft_putstr(name[i++]);
		ft_putendl(": No such file or directory");
	}
}

void	get_multiple_arg(char ***argv, t_flags flags)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	not_file(argv[2]);
	files_not_repo(argv[0], flags);
	while (argv[1][l])
		l++;
	while (argv[1][i])
	{
		if (l > 1)
		{
			if (i > 0 || argv[0][0])
				ft_putendl("");
			ft_putstr(argv[1][i]);
			ft_putendl(":");
		}
		ft_opendir(flags, argv[1][i]);
		i++;
	}
}
