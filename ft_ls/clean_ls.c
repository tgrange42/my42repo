/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:26:57 by tgrange           #+#    #+#             */
/*   Updated: 2017/05/24 15:59:31 by tgrange          ###   ########.fr       */
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
	// free(*tab);
}

void	clean_tabn(char ***tab, int n)
{
	int		i;

	i = 0;
	if (*tab)
	{
		while (i < n)
			ft_strdel(tab[i++]);
	}
	// free(*tab);
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
			ft_strdel(&tmp2->path);
			ft_strdel(&tmp2->grp);
			ft_strdel(&tmp2->author);
			ft_strdel(&tmp2->perms);
			ft_strdel(&tmp2->major);
			ft_strdel(&tmp2->size);
			ft_strdel(&tmp2->links);
			clean_tab(&tmp2->date);
			ft_strdel(&tmp2->linked_file);
			free(tmp2);
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
