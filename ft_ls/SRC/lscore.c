/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lscore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:39:04 by tgrange           #+#    #+#             */
/*   Updated: 2017/03/17 16:54:48 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_list	*get_files_names(char *path, t_flags flags)
{
	DIR				*stream;
	struct dirent	*list;
	t_list			*tmp;
	t_list			*begin;

	begin = NULL;
	stream = opendir(path);
	while ((list = readdir(stream)) != NULL)
	{
		if (list->d_name[0] != '.' || flags.a_flag)
		{
			tmp = ft_lstnew((char *)list->d_name, ft_strlen(list->d_name));
			if (list->d_type == 4)
				tmp->content_size = 1;
			else
			{
				tmp->content_size = 0;
			}
			ft_lstincre(&begin, tmp);
		}
	}
	closedir(stream);
	return (begin);
}

void	print_dir(t_flags flags, t_list **files)
{
	t_list		*tmp;

	tmp = *files;
	(void)flags;
	while (tmp != NULL)
	{
		if (tmp->content)
			ft_putendl(tmp->content);
		tmp = tmp->next;
	}
}

void	ft_opendir(t_flags flags, char *name)
{
	t_list	*files;
	t_info	*infos;

	files = get_files_names(name, flags);
	sort_list_alpha(&files);
	infos = convert_t_list_to_t_info(files);
	if (flags.t_flag)
		lst_t_flag = sort_list_time(&infos);
	if (flags.r_flag)
		rev_list(&infos);
	print_dir(flags, &files);
	if (flags.R_flag)
		while (infos != NULL)
		{
			if (infos->type == 'd' && ft_strcmp(infos->name, "..") &&
				ft_strcmp(infos->name, "."))
			{
				ft_putendl("");
				ft_putstr(get_path(name, infos->name));
				ft_putendl(":");
				ft_opendir(flags, get_path(name, infos->name));
			}
			infos = infos->next;
		}
}

void	get_multiple_arg(char **argv, t_flags flags)
{
	int		i[3];

	i[0] = 1;
	i[1] = 0;
	i[2] = 0;
	while (argv[i[0]] && argv[i[0]][0] == '-')
		i[0]++;
	while (argv[i[0] + i[1]])
	{
		i[1]++;
		i[2]++;
	}
	if (!i[2])
		ft_opendir(flags, ft_strdup("."));
	i[1] = 0;
	while (i[1] < i[2])
	{
		if (i[2] > 1)
		{
			ft_putstr(argv[i[0] + i[1]]);
			ft_putendl(":");
		}
		ft_opendir(flags, ft_strdup(argv[i[0] + i[1]]));
		i[1]++;
	}
}
