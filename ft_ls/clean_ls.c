/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:26:57 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/04 15:46:58 by tgrange          ###   ########.fr       */
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
	lst = NULL;
}

void	clean_t_info(t_info *lst, t_flags flags)
{
	t_info		*tmp;

	if (flags.grand_r_flag)
		while (lst)
		{
			tmp = lst->next;
			lst = tmp;
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
