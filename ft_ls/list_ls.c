/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:57:40 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/02 17:15:00 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	ft_swapptr((void **)&m1->path, (void **)&m2->path);
	if (m1->grp && m2->grp)
		ft_swapptr((void **)&m1->grp, (void **)&m2->grp);
	if (m1->author && m2->author)
		ft_swapptr((void **)&m1->author, (void **)&m2->author);
	if (m1->perms && m2->perms)
		ft_swapptr((void **)&m1->perms, (void **)&m2->perms);
	if (m1->date_int && m2->date_int)
		ft_swapptr((void **)&m1->date_int, (void **)&m2->date_int);
	if (m1->size && m2->size)
		ft_swap((void *)&m1->size, (void *)&m2->size);
	if (m1->type && m2->type)
		ft_swap((void *)&m1->type, (void *)&m2->type);
	if (m1->links && m2->links)
		ft_swap((void *)&m1->links, (void *)&m2->links);
	if (m1->date && m2->date)
	{
		ft_swap((void *)m1->date[0], (void *)m2->date[0]);
		ft_swap((void *)m1->date[1], (void *)m2->date[1]);
		ft_swap((void *)m1->date[2], (void *)m2->date[2]);
	}
}

void	sort_list_alpha(t_info **begin_lst)
{
	int		not_sorted;
	t_info	*tmp;

	not_sorted = 1;
	while (not_sorted)
	{
		tmp = *begin_lst;
		not_sorted = 0;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->name, tmp->next->name) > 0)
			{
				not_sorted = 1;
				swap_t_info(tmp, tmp->next);
			}
			tmp = tmp->next;
		}
	}
}

t_info	*create_t_info(char *name_file, char *path)
{
	t_info			*tmp;
	struct stat		gettype;

	if (!(tmp = (t_info *)ft_memalloc(sizeof(t_info))))
		return (NULL);
	lstat(path, &gettype);
	tmp->name = ft_strdup(name_file);
	tmp->perms = ft_strdup("---------\0");
	tmp->type = get_type(gettype);
	tmp->path = path;
	tmp->next = NULL;
	return (tmp);
}

void	pushback_t_info(t_info *new, t_info **begin)
{
	t_info	*tmp;

	if (!*begin)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
