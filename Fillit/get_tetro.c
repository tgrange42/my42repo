/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:15:01 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/09 04:42:12 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_there_a_tetriminos(char *file_name)
{
	int		fd;
	int		i;
	char	buf;
	int		n;
	char	tmp;

	tmp = 'L';
	n = 0;
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n' && tmp == '\n')
			n++;
		if (buf == '\n' && tmp != '\n')
			i++;
		tmp = buf;
	}
	close(fd);
	if (i == 4 || (i > 4 && n + 1 == i / 4 && i % 4 == 0))
		return (1);
	return (0);
}

int		get_nb_tetro(char *file_name)
{
	int		fd;
	int		i;
	char	buf;
	char	tmp;

	tmp = 'L';
	i = 1;
	fd = open(file_name, O_RDONLY);
	if (!is_there_a_tetriminos(file_name))
		return (0);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n' && tmp == '\n')
			i++;
		tmp = buf;
	}
	close(fd);
	return (i);
}

char	*get_this_tetro(int which_tetro, int fd)
{
	int		i;
	char	tmp;
	char	buf;
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(ret) * 21)))
		return (NULL);
	tmp = 'L';
	i = 0;
	while (i < which_tetro && read(fd, &buf, 1))
	{
		if (buf == '\n' && tmp == '\n')
			i++;
		tmp = buf;
	}
	i = 0;
	while (i < 20 && read(fd, &buf, 1))
		ret[i++] = buf;
	ret[i] = '\0';
	close(fd);
	return (ret);
}

char	**get_tetrominos(char *file_name)
{
	int		nb_tetro;
	char	**ret;
	int		i;
	int		fd;

	i = 0;
	nb_tetro = get_nb_tetro(file_name);
	if (!(ret = (char **)malloc(sizeof(ret) * (size_t)(nb_tetro + 1))))
		return (NULL);
	while (i < nb_tetro)
	{
		fd = open(file_name, O_RDONLY);
		ret[i] = get_this_tetro(i, fd);
		close(fd);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
