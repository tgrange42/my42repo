/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:29:13 by tgrange           #+#    #+#             */
/*   Updated: 2017/09/20 14:45:45 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_and_free(char *s1, char *s2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (tmp);
}

int		get_line(const int fd, char **stock, char **line)
{
	int		l;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	int		read_ret;

	read_ret = 1;
	tmp = *stock;
	while (!ft_countchar(tmp, '\n') && read_ret)
	{
		if ((read_ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[read_ret] = '\0';
		tmp = join_and_free(tmp, buffer);
	}
	l = ft_strlento(tmp, 0, '\n');
	*line = ft_strsub(tmp, 0, l);
	*stock = ft_strsub(tmp, l + 1, ft_strlen(tmp) - l);
	if (!read_ret && !tmp[0])
		return (0);
	ft_strdel(&tmp);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*stock = NULL;
	int				ret;

	if (BUFF_SIZE < 1 || fd < 0)
		return (-1);
	ret = get_line(fd, &stock, line);
	return (ret);
}
