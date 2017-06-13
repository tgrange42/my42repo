/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:26:57 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/09 18:13:29 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	rm_t_info(t_info *lst)
{
	ft_strdel(&lst->name);
	ft_strdel(&lst->path);
	ft_strdel(&lst->grp);
	ft_strdel(&lst->author);
	ft_strdel(&lst->perms);
	ft_strdel(&lst->major);
	ft_strdel(&lst->size);
	ft_strdel(&lst->links);
	ft_strdel(&lst->linked_file);
	del_tabstr(&lst->date);
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
			rm_t_info(tmp2);
			free(tmp2);
			tmp2 = tmp;
		}
}

void	clean_lst(t_info **lst)
{
	t_info		*tmp2;
	t_info		*tmp;

	tmp2 = *lst;
	while (tmp2)
	{
		tmp = tmp2->next;
		rm_t_info(tmp2);
		free(tmp2);
		tmp2 = tmp;
	}
}

void	next_rm(t_info **lst)
{
	t_info	*tmp;

	tmp = *lst;
	tmp = tmp->next;
	rm_t_info(tmp);
	*lst = tmp;
}

void	jump_t_info(t_info **lst, char *name)
{
	t_info	*tmp;

	tmp = *lst;
	while (tmp && tmp->next && !ft_strcmp(tmp->next->name, name))
		tmp = tmp->next;
	tmp->next = tmp->next->next;
}
