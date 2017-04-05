/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:40:54 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/05 12:54:31 by tgrange          ###   ########.fr       */
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
	while (argv[nb] && argv[nb][0] == '-')
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

char	**sort_ascii(char **argv, int argc)
{
	int		not_sorted;
	int		i;
	char	**ret;

	ret = clean_args(argv, argc);
	not_sorted = 1;
	while (not_sorted)
	{
		i = 0;
		not_sorted = 0;
		while (ret[i + 1])
		{
			if (ft_strcmp(ret[i], ret[i + 1]) > 0)
			{
				not_sorted = 1;
				ft_swap((void *)ret[i], (void *)ret[i + 1]);
			}
			i++;
		}
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	t_flags		flags;
	char		**clean_arg;

	initialize_struct_flags(&flags);
	get_multiple_flags(argv, &flags);
	clean_arg = sort_ascii(argv, argc);
	get_multiple_arg(clean_arg, flags);
	return (0);
}
