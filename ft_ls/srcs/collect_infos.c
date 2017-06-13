/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:07:30 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/09 17:29:14 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	get_perms2(struct stat buf, char *perms, int i)
{
	if (++i > -1 && buf.st_mode & S_IROTH)
		perms[i] = 'r';
	if (++i > -1 && buf.st_mode & S_IWOTH)
		perms[i] = 'w';
	if (++i > -1 && buf.st_mode & S_ISVTX && buf.st_mode & S_IXOTH)
		perms[i] = 't';
	else if (buf.st_mode & S_ISVTX)
		perms[i] = 'T';
	else if (buf.st_mode & S_IXOTH)
		perms[i] = 'x';
}

void	get_perms(struct stat buf, char *perms)
{
	int		i;

	i = -1;
	if (++i > -1 && buf.st_mode & S_IRUSR)
		perms[i] = 'r';
	if (++i > -1 && buf.st_mode & S_IWUSR)
		perms[i] = 'w';
	if (++i > -1 && buf.st_mode & S_IXUSR && S_ISUID & buf.st_mode)
		perms[i] = 's';
	else if (!(buf.st_mode & S_IXUSR) && S_ISUID & buf.st_mode)
		perms[i] = 'S';
	else if (buf.st_mode & S_IXUSR)
		perms[i] = 'x';
	if (++i > -1 && buf.st_mode & S_IRGRP)
		perms[i] = 'r';
	if (++i > -1 && buf.st_mode & S_IWGRP)
		perms[i] = 'w';
	if (++i > -1 && buf.st_mode & S_IXGRP && S_ISUID & buf.st_mode)
		perms[i] = 's';
	else if (!(buf.st_mode & S_IXGRP) && S_ISUID & buf.st_mode)
		perms[i] = 'S';
	else if (buf.st_mode & S_IXGRP)
		perms[i] = 'x';
	get_perms2(buf, perms, i);
}

char	get_type(struct stat buf)
{
	if (S_ISDIR(buf.st_mode))
		return ('d');
	if (S_ISCHR(buf.st_mode))
		return ('c');
	if (S_ISLNK(buf.st_mode))
		return ('l');
	if (S_ISBLK(buf.st_mode))
		return ('b');
	if (S_ISREG(buf.st_mode))
		return ('-');
	if (S_ISFIFO(buf.st_mode))
		return ('p');
	if (S_ISSOCK(buf.st_mode))
		return ('s');
	return ('-');
}

void	get_fifo(t_info *lst, struct stat buf)
{
	int		i;
	char	*tmp;

	lst->major = ft_itoa(major(buf.st_rdev));
	i = ft_strlen(lst->major);
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * (i + 2))))
		return ;
	tmp = ft_strcpy(tmp, lst->major);
	tmp[i] = ',';
	ft_strdel(&lst->major);
	lst->major = tmp;
	lst->size = ft_itoa(minor(buf.st_rdev));
}

void	collect_infos(t_info **lst)
{
	t_info			*tmp;
	struct stat		buf;
	struct passwd	*test;

	tmp = *lst;
	while (tmp)
	{
		lstat(tmp->path, &buf);
		test = getpwuid(buf.st_uid);
		if (test)
		{
			get_group_author(buf, tmp);
			get_perms(buf, tmp->perms);
			if (tmp->type == 'c' || tmp->type == 'b' || tmp->type == 'p')
				get_fifo(tmp, buf);
			else
				tmp->size = ft_itoa(buf.st_size);
			if (!(tmp->linked_file = (char *)ft_memalloc(sizeof(char) * 151)))
				return ;
			readlink(tmp->path, tmp->linked_file, 150);
		}
		else
			tmp->error = 1;
		tmp = tmp->next;
	}
}
