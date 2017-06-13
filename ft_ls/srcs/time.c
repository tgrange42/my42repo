/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:44:01 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/09 17:13:27 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		get_time(t_info *lst, int birth)
{
	struct stat		buf;
	char			date[27];

	lstat(lst->path, &buf);
	if (birth)
		lst->date_int = buf.st_birthtimespec.tv_sec;
	else
		lst->date_int = buf.st_mtimespec.tv_sec;
	date[25] = '\0';
	ft_strcpy(date, ctime(&lst->date_int));
	lst->date = ft_strsplit(date, ' ');
}

void		pushback_t_info_time(t_info *new, t_info **begin)
{
	t_info	*tmp;
	t_info	*tmp2;
	int		i;

	i = 0;
	if (!*begin)
		*begin = new;
	else
	{
		tmp = *begin;
		tmp2 = tmp;
		while (tmp2 && tmp && tmp->date_int > new->date_int)
			equal_equal(&tmp2, &tmp, &tmp, &tmp->next);
		while (tmp2 && tmp && tmp->date_int == new->date_int &&
			ft_strcmp(tmp->name, new->name) < 0)
			equal_equal(&tmp2, &tmp, &tmp, &tmp->next);
		if (tmp == *begin)
			equal_equal(&new->next, &tmp, begin, &new);
		else
			equal_equal(&new->next, &tmp, &tmp2->next, &new);
	}
}
