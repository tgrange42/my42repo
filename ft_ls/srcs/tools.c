/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:28:41 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/09 17:29:29 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*get_path(char *actual_path, char *dir_name)
{
	char	*path;
	int		len;

	len = ft_strlen(actual_path) + ft_strlen(dir_name) + 2;
	if (!(path = (char *)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	path = ft_strcpy(path, actual_path);
	if (!(actual_path[0] == '/' && ft_strlen(actual_path) == 1))
		path[ft_strlen(actual_path)] = '/';
	path = ft_strcat(path, dir_name);
	return (path);
}

size_t	get_nb_files(t_info **files)
{
	size_t	ret;
	t_info	*tmp;

	tmp = *files;
	ret = 0;
	while (tmp)
	{
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}

void	get_group_author(struct stat buf, t_info *infos)
{
	struct passwd	*data_author;
	struct group	*data_grp;

	data_author = getpwuid(buf.st_uid);
	infos->author = ft_strdup(data_author->pw_name);
	data_grp = getgrgid(buf.st_gid);
	infos->grp = ft_strdup(data_grp->gr_name);
	infos->blocks = buf.st_blocks;
	infos->date[3][5] = '\0';
	infos->date[4][4] = '\0';
	infos->links = ft_itoa(buf.st_nlink);
}

void	equal_equal(t_info **t1, t_info **t2, t_info **s1, t_info **s2)
{
	*t1 = *t2;
	*s1 = *s2;
}

char	***create_tab_nb(int size, int length)
{
	int		i;
	char	***ret;

	i = 0;
	if (!(ret = (char ***)ft_memalloc(sizeof(ret) * size)))
		return (NULL);
	while (i < size)
		if (!(ret[i++] = (char **)ft_memalloc(sizeof(ret[i]) * length)))
			return (0);
	return (ret);
}
