/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:44:01 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/04 15:46:40 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**get_time_char(char *name, time_t *int_date)
{
	struct stat		buf;
	char			date[27];
	time_t			time;

	lstat(name, &buf);
	time = buf.st_mtimespec.tv_sec;
	date[26] = '\0';
	ft_strcpy(date, ctime(&time));
	*int_date = time;
	return (ft_strsplit(date, ' '));
}

void		get_date(t_info **lst)
{
	t_info	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp->date = get_time_char(tmp->path, &tmp->date_int);
		tmp = tmp->next;
	}
}

void		sort_list_time(t_info **lst)
{
	t_info	*tmp;
	int		not_sorted;

	get_date(lst);
	not_sorted = 1;
	while (not_sorted)
	{
		tmp = *lst;
		not_sorted = 0;
		while (tmp->next)
		{
			if (tmp->date_int < tmp->next->date_int)
			{
				not_sorted = 1;
				swap_t_info(tmp, tmp->next);
			}
			tmp = tmp->next;
		}
	}
}
