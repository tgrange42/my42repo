/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lscore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:39:04 by tgrange           #+#    #+#             */
/*   Updated: 2017/05/23 17:34:49 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info	*get_files_names(char *path, t_flags flags, char *name)
{
	DIR				*stream;
	struct dirent	*list;
	t_info			*tmp;
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
		{
			tmp = create_t_info(list->d_name, list->d_type, get_path(path,
				list->d_name));
			pushback_t_info(tmp, &ret);
		}
	}
	closedir(stream);
	return (ret);
}

void	recursive_ls(t_info **infos, t_flags flags)
{
	t_info	*tmp;

	tmp = *infos;
	while (tmp)
	{
		if (tmp->type == 'd' && ft_strcmp(tmp->name, "..") &&
			ft_strcmp(tmp->name, "."))
		{
			ft_putbegl(tmp->path);
			ft_putendl(":");
			ft_opendir(flags, tmp->path, NULL, tmp->name);
		}
		next_rm(&tmp);
	}
}

void	ft_opendir(t_flags flags, char *name, t_info *infos, char *pure_name)
{
	if (!(infos = get_files_names(name, flags, pure_name)))
		return ;
	sort_list_alpha(&infos);
	if (flags.t_flag)
		sort_list_time(&infos, flags);
	if (flags.r_flag)
		rev_list(&infos);
	if (flags.l_flag)
		collect_infos(&infos, flags);
	print_dir(flags, &infos, 1);
	if (flags.grand_r_flag)
		recursive_ls(&infos, flags);
	clean_t_info(&infos, flags);
}

void	files_not_repo(char **names, t_flags flags, int nb)
{
	int			i;
	t_info		*files;
	t_info		*tmp;

	if (!names[0])
		return ;
	files = NULL;
	i = 0;
	while (names[i])
	{
		tmp = create_t_info(names[i], 0, names[i]);
		pushback_t_info(tmp, &files);
		i++;
	}
	if (flags.t_flag)
		sort_list_time(&files, flags);
	if (flags.r_flag)
		rev_list(&files);
	if (flags.l_flag)
		collect_infos(&files, flags);
	(void)nb;
	// clean_tabn(&names, nb);
	print_dir(flags, &files, 0);
}

void	get_multiple_arg(char ***argv, t_flags flags, int nb)
{
	int		i;
	int		l;

	i = 0;
	l = ft_tablen(argv[1]);
	not_file(argv[2], nb);
	files_not_repo(argv[0], flags, nb);
	while (argv[1][i])
	{
		if (l > 1 || argv[0][0] || argv[2][0])
		{
			if (i > 0 || argv[0][0])
				ft_putendl("");
			ft_putstr(argv[1][i]);
			ft_putendl(":");
		}
		ft_opendir(flags, argv[1][i], NULL, argv[1][i]);
		i++;
	}
	// clean_tabn(&argv[1], nb);
	// free(argv);
}
