/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:30:54 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/12 15:53:15 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**clean_args(char **argv, int argc)
{
	int		nb;
	char	**ret;
	int		i;

	i = 0;
	nb = 1;
	while (argv[nb] && argv[nb][0] == '-' && argv[nb][1])
		nb++;
	if (!(ret = (char **)ft_memalloc(sizeof(ret) * (argc - nb + 2))))
		return (NULL);
	if (nb == argc)
		ret[0] = ft_strdup(".");
	else
		while (nb < argc)
			ret[i++] = ft_strdup(argv[nb++]);
	return (ret);
}

void	sort_ascii(char **str)
{
	int		not_sorted;
	int		i;
	char	*tmp;

	not_sorted = 1;
	while (not_sorted)
	{
		i = 0;
		not_sorted = 0;
		while (str && str[i + 1])
		{
			if (ft_strcmp(str[i], str[i + 1]) > 0)
			{
				not_sorted = 1;
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
			i++;
		}
	}
}

/*
**	ret[0] = files
**	ret[1] = repo
**	ret[2] = name error
*/

char	***sort_args_type(char **argv, int nb, int i, int *j)
{
	char			***ret;
	DIR				*trash;
	struct stat		buf;

	ret = create_tab_nb(4, nb);
	while (argv[i])
	{
		errno = 0;
		trash = opendir(argv[i]);
		lstat(argv[i], &buf);
		if (errno == ENOENT)
			ret[2][j[0]++] = argv[i++];
		else if (errno == ENOTDIR || (S_ISLNK(buf.st_mode) &&
			argv[i][ft_strlen(argv[i]) - 1] != '/' && j[3]) || j[4])
			ret[0][j[1]++] = argv[i++];
		else
			ret[1][j[2]++] = argv[i++];
		if (trash)
			closedir(trash);
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	t_flags		flags;
	char		**clean_arg;
	char		***all_args;
	int			tab[5];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	initialize_struct_flags(&flags);
	get_multiple_flags(argv, &flags);
	clean_arg = clean_args(argv, argc);
	tab[3] = flags.l_flag;
	tab[4] = flags.d_flag;
	all_args = sort_args_type(clean_arg, ft_tablen(clean_arg) + 1, 0, tab);
	sort_ascii(all_args[0]);
	get_multiple_arg(all_args, flags);
	return (0);
}
