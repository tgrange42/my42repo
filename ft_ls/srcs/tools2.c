/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:21:22 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/09 18:13:46 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_info		*tab_to_t_info(char **tab, t_flags flags)
{
	int		i;
	t_info	*ret;

	i = 0;
	ret = NULL;
	while (tab[i])
	{
		create_t_info(tab[i], ft_strdup(tab[i]), flags, &ret);
		i++;
	}
	if (flags.r_flag)
		rev_list(&ret);
	return (ret);
}

void		del_tabstr(char ***str)
{
	int		i;

	i = 0;
	if (!str || !*str)
		return ;
	while ((*str)[i])
		ft_strdel(&((*str)[i++]));
	free(*str);
	*str = NULL;
}
