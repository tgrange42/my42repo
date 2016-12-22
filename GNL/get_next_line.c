/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:41:02 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/22 17:54:57 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_gnl	*get_t_gnl(int fd, t_gnl **begin)
{
	t_gnl	*tmp;

	tmp = *begin;
	while (!tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		 if (!(tmp = (t_gnl *)ft_memalloc(sizeof(tmp))))
		 	return (NULL);
		 // ft_strnew(tmp->buf);
		 tmp->next =NULL;
		 tmp->fd = fd;
		 tmp->i = 0;
	}
	return (tmp);
}

static int		get_the_line(t_gnl *this_fd, char **line)
{
	int		n;
	size_t	len;

	n = 0;
	*line = ft_strnew(0);
	if (!this_fd->buf[this_fd->i] && read(this_fd->fd, this_fd->buf, BUFF_SIZE) == -1)
		return (-1);
	while (!n)
	{
		len = ft_strlento(this_fd->buf, (size_t)this_fd->i, '\n');
		*line  = ft_strjoin(*line, ft_strsub(this_fd->buf, (unsigned int)this_fd->i, len));
		this_fd->i += len;
		if (!this_fd->buf[this_fd->i])
		{
			ft_strclr(this_fd->buf);
			if (!read(this_fd->fd, this_fd->buf, BUFF_SIZE))
				return (1);
		}
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*fd_stock = NULL;
	t_gnl			*current;

	if (fd < 0)
		return (-1);
	if (!(current = get_t_gnl(fd, &fd_stock)))
		return (-1);
	return (get_the_line(current, line));
}
