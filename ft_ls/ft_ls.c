/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:30:54 by tgrange           #+#    #+#             */
/*   Updated: 2017/05/24 16:26:18 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	char	***ret;
	DIR		*trash;

	if (!(ret = (char ***)ft_memalloc(sizeof(char **) * 4)))
		return (NULL);
	if (!(ret[0] = (char **)ft_memalloc(sizeof(char *) * nb)))
		return (NULL);
	if (!(ret[1] = (char **)ft_memalloc(sizeof(char *) * nb)))
		return (NULL);
	if (!(ret[2] = (char **)ft_memalloc(sizeof(char *) * nb)))
		return (NULL);
	while (argv[i])
	{
		errno = 0;
		trash = opendir(argv[i]);
		if (!errno || errno == EACCES)
			ret[1][j[2]++] = argv[i++];
		else if (errno == ENOENT)
			ret[2][j[0]++] = argv[i++];
		else if (errno == ENOTDIR)
			ret[0][j[1]++] = argv[i++];
		if (trash)
			closedir(trash);
	}
	// clean_tab(&argv);
	return (ret);
}

int		main(int argc, char **argv)
{
	t_flags		flags;
	char		**clean_arg;
	char		***all_args;
	int			tab[3];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	initialize_struct_flags(&flags);
	get_multiple_flags(argv, &flags);
	clean_arg = clean_args(argv, argc);
	all_args = sort_args_type(clean_arg, ft_tablen(clean_arg) + 1, 0, tab);
	sort_ascii(all_args[0]);
	sort_ascii(all_args[1]);
	sort_ascii(all_args[2]);
	get_multiple_arg(all_args, flags, ft_tablen(clean_arg) + 1);
	clean_tab(&all_args[0]);
	clean_tab(&all_args[1]);
	clean_tab(&all_args[2]);
	// free(all_args);
	// while (1)
	// 	;
	return (0);
}
