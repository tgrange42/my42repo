/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:07:30 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/04 15:46:46 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_group_author(struct stat buf, char **author, char **group,
	size_t *blocks)
{
	struct passwd	*data_author;
	struct group	*data_grp;

	data_author = getpwuid(buf.st_uid);
	*author = ft_strdup(data_author->pw_name);
	data_grp = getgrgid(buf.st_gid);
	*group = ft_strdup(data_grp->gr_name);
	*blocks = buf.st_blocks;
}

void	get_perms(struct stat buf, char *perms)
{
	int		i;

	i = -1;
	if (++i > -1 && buf.st_mode & S_IRUSR)
		perms[i] = 'r';
	if (++i > -1 && buf.st_mode & S_IWUSR)
		perms[i] = 'w';
	if (++i > -1 && buf.st_mode & S_IXUSR)
		perms[i] = 'x';
	if (++i > -1 && buf.st_mode & S_IRGRP)
		perms[i] = 'r';
	if (++i > -1 && buf.st_mode & S_IWGRP)
		perms[i] = 'w';
	if (++i > -1 && buf.st_mode & S_IXGRP)
		perms[i] = 'x';
	if (++i > -1 && buf.st_mode & S_IROTH)
		perms[i] = 'r';
	if (++i > -1 && buf.st_mode & S_IWOTH)
		perms[i] = 'w';
	if (++i > -1 && buf.st_mode & S_IXOTH)
		perms[i] = 'x';
}

char	get_type(struct stat buf)
{
	if (buf.st_mode & S_IFIFO)
		return ('F');
	else if (buf.st_mode & S_IFDIR)
		return ('d');
	else if (buf.st_mode & S_IFREG)
		return ('-');
	else if (buf.st_mode & S_IFLNK)
		return ('l');
	else if (buf.st_mode & S_IFSOCK)
		return ('s');
	else if (buf.st_mode & S_IFWHT)
		return ('W');
	else if (buf.st_mode & S_IFBLK)
		return ('B');
	else if (buf.st_mode & S_IFCHR)
		return ('c');
	return ('-');
}

void	collect_infos(t_info **lst)
{
	t_info			*tmp;
	struct stat		buf;

	tmp = *lst;
	while (tmp)
	{
		lstat(tmp->path, &buf);
		get_group_author(buf, &tmp->author, &tmp->grp, &tmp->blocks);
		get_perms(buf, tmp->perms);
		tmp->size = ft_itoa(buf.st_size);
		tmp->links = ft_itoa(buf.st_nlink);
		tmp->type = get_type(buf);
		tmp->date = get_time_char(tmp->path, &tmp->date_int);
		tmp->date[3][5] = '\0';
		tmp = tmp->next;
	}
}
