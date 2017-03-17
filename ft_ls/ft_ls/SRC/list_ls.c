/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:57:40 by tgrange           #+#    #+#             */
/*   Updated: 2017/03/17 17:29:24 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	rev_list(t_info **lst)
{
	t_info	*tmp;
	t_info	*tmp2;
	t_info	*current;

	tmp = NULL;
	current = *lst;
	while (current)
	{
		tmp2 = current->next;
		current->next = tmp;
		tmp = current;
		current = tmp2;
	}
	*lst = tmp;
}

void	swap_t_info(t_info *m1, t_info *m2)
{
	ft_swapptr((void **)&m1->name, (void **)&m2->name);
	ft_swapptr((void **)&m1->grp, (void **)&m2->grp);
	ft_swapptr((void **)&m1->author, (void **)&m2->author);
	ft_swapptr((void **)&m1->perms, (void **)&m2->perms);
	ft_swapptr((void **)&m1->date_int, (void **)&m2->date_int);
	ft_swap((void *)&m1->size, (void *)&m2->size);
	ft_swap((void *)&m1->type, (void *)&m2->type);
	ft_swap((void *)&m1->links, (void *)&m2->links);
	ft_swaptriple((void ***)&m1->date, (void *)**&m2->date);
}

void	sort_list_alpha(t_list **begin_lst)
{
	int		not_sorted;
	t_list	*tmp;

	not_sorted = 1;
	while (not_sorted)
	{
		not_sorted = 0;
		tmp = *begin_lst;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->content, tmp->next->content) > 0)
			{
				not_sorted = 1;
				ft_swaplst(tmp, tmp->next);
			}
			tmp = tmp->next;
		}
	}
}

void	

t_info	*convert_t_list_to_t_info(t_list *files)
{
	t_info		*ret;

	while (files)
	{

	}
}
