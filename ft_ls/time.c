/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:44:01 by tgrange           #+#    #+#             */
/*   Updated: 2017/05/22 16:43:53 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**get_time_char(char *name, time_t *int_date, int birth)
{
	struct stat		buf;
	char			date[27];
	time_t			time;

	lstat(name, &buf);
	if (birth)
		time = buf.st_birthtimespec.tv_sec;
	else
		time = buf.st_mtimespec.tv_sec;
	date[25] = '\0';
	ft_strcpy(date, ctime(&time));
	*int_date = time;
	return (ft_strsplit(date, ' '));
}

void		get_date(t_info **lst, t_flags flags)
{
	t_info	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp->date = get_time_char(tmp->path, &tmp->date_int,
			flags.grand_u_flag);
		tmp = tmp->next;
	}
}

void		sort_list_time(t_info **lst, t_flags flags)
{
	t_info	*tmp;
	int		not_sorted;

	get_date(lst, flags);
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
