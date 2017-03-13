/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:32:40 by tgrange           #+#    #+#             */
/*   Updated: 2017/03/09 16:57:28 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*get_mode(struct stat buf, char *perms)
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
	return (perms);
}

static void	get_links(struct stat buf)
{
	ft_putstr("Nombre de liens: ");
	ft_putnbr(buf.st_nlink);
	ft_putchar('\n');
}

static void	get_author_and_group(struct stat buf)
{
	struct passwd	*data_author;
	struct group	*data_grp;

	data_author = getpwuid(buf.st_uid);
	ft_putstr("Proprietaire: ");
	ft_putendl(data_author->pw_name);
	data_grp = getgrgid(buf.st_gid);
	ft_putstr("Groupe: ");
	ft_putendl(data_grp->gr_name);
}

static void	get_type(struct stat buf)
{
	ft_putstr("Type: ");
	if (buf.st_mode & S_IFIFO)
		ft_putendl("FIFO");
	else if (buf.st_mode & S_IFDIR)
		ft_putendl("Dossier");
	else if (buf.st_mode & S_IFREG)
		ft_putendl("Fichier");
	else if (buf.st_mode & S_IFLNK)
		ft_putendl("Lien symbolique");
	else if (buf.st_mode & S_IFSOCK)
		ft_putendl("Socket");
	else if (buf.st_mode & S_IFWHT)
		ft_putendl("Whiteout");
	else if (buf.st_mode & S_IFBLK)
		ft_putendl("Block special");
	else if (buf.st_mode & S_IFCHR)
		ft_putendl("Caractere special");
}

static void	get_size(struct stat buf)
{
	ft_putstr("Taille: ");
	ft_putnbr(buf.st_size);
	ft_putendl(" octets");
}

static char	*simple_rotn(char *str, int n, int begin)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = begin;
		while (str[j])
		{
			str[j] = str[j + 1];
			j++;
		}
		i++;
	}
	return (str);
}

static char	*erase_last_n_char(char *str, int n)
{
	int		l;

	l = ft_strlen(str) - n;
	while (str[l + 1])
	{
		str[l] = '\0';
		l++;
	}
	return (str);
}

static char	*cut_date(char *date)
{
	date = simple_rotn(date, 4, 0);
	date = erase_last_n_char(date, 5);
	date = simple_rotn(date, 1, 4);
	return (date);
}

static void	get_last_modi(struct stat buf)
{
	char	buff[27];
	time_t	time;

	time = buf.st_mtimespec.tv_sec;
	buff[26] = '\0';
	ft_strcpy(buff, cut_date(ctime(&time)));
	ft_putstr("Date de derniere modification: ");
	ft_putendl(buff);
}

void		get_stats(char *name_of_file)
{
	struct stat		buf;

	lstat(name_of_file, &buf);
	ft_putstr("Nom: ");
	ft_putendl(name_of_file);
	get_type(buf);
	ft_putstr("Modes: ");
	ft_putendl(get_mode(buf, ft_strdup("---------")));
	get_links(buf);
	get_author_and_group(buf);
	get_size(buf);
	get_last_modi(buf);
}
