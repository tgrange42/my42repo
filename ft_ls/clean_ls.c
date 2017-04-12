/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:26:57 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/12 02:57:55 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	clean_tab(char ***tab)
{
	if (*tab)
	{
		while (**tab)
			ft_strdel(*tab);
	}
	free(*tab);
}

void	rm_t_info(t_info *lst)
{
	ft_strdel(&lst->name);
	ft_strdel(&lst->grp);
	ft_strdel(&lst->author);
	ft_strdel(&lst->perms);
	ft_strdel(&lst->size);
	ft_strdel(&lst->links);
	clean_tab(&lst->date);
	lst = NULL;
}

void	clean_t_info(t_info **lst, t_flags flags)
{
	t_info		*tmp2;
	t_info		*tmp;

	tmp2 = *lst;
	if (flags.grand_r_flag)
		while (tmp2)
		{
			tmp = tmp2->next;
			ft_strdel(&tmp2->name);
			ft_strdel(&tmp2->grp);
			ft_strdel(&tmp2->author);
			ft_strdel(&tmp2->perms);
			ft_strdel(&tmp2->size);
			ft_strdel(&tmp2->links);
			clean_tab(&tmp2->date);
			tmp2 = tmp;
		}
}

void	next_rm(t_info **lst)
{
	t_info	*tmp;

	tmp = *lst;
	tmp = tmp->next;
	rm_t_info(*lst);
	*lst = tmp;
}

void	not_file(char **name)
{
	int		i;

	i = 0;
	while (name[i])
	{
		ft_putstr("ls: ");
		ft_putstr(name[i++]);
		ft_putendl(": No such file or directory");
	}
}
