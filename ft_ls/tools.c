/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:28:41 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/05 16:37:17 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_path(char *actual_path, char *dir_name)
{
	char	*path;
	int		len;

	len = ft_strlen(actual_path) + ft_strlen(dir_name) + 2;
	if (!(path = (char *)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	path = ft_strcpy(path, actual_path);
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
