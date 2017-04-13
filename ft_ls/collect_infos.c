/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:07:30 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/13 07:51:35 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_group_author(struct stat buf, t_info *infos)
{
	struct passwd	*data_author;
	struct group	*data_grp;

	data_author = getpwuid(buf.st_uid);
	infos->author = ft_strdup(data_author->pw_name);
	data_grp = getgrgid(buf.st_gid);
	infos->grp = ft_strdup(data_grp->gr_name);
	infos->blocks = buf.st_blocks;
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
	if (++i > -1 && buf.st_mode & S_ISVTX)
		perms[i] = 't';
	else if (i > -1 && buf.st_mode & S_IXOTH)
		perms[i] = 'x';
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
	if (S_ISWHT(buf.st_mode))
		return ('-');
	return ('-');
}

void	get_acl(t_info *infos)
{
	int		ret;

	errno = 0;
	ret = listxattr(infos->path, NULL, 0, XATTR_NOFOLLOW);
	if (!ret)
		return ;
	else if (ret > 0)
		infos->perms[9] = '@';
}

void	collect_infos(t_info **lst)
{
	t_info			*tmp;
	struct stat		buf;

	tmp = *lst;
	while (tmp)
	{
		lstat(tmp->path, &buf);
		get_group_author(buf, tmp);
		get_perms(buf, tmp->perms);
		tmp->size = ft_itoa(buf.st_size);
		tmp->links = ft_itoa(buf.st_nlink);
		tmp->type = get_type(buf);
		tmp->date = get_time_char(tmp->path, &tmp->date_int);
		tmp->date[3][5] = '\0';
		tmp->date[4][4] = '\0';
		if (!(tmp->linked_file = (char *)ft_memalloc(sizeof(char) * 151)))
			return ;
		readlink(tmp->path, tmp->linked_file, 150);
		get_acl(tmp);
		tmp = tmp->next;
	}
}
