/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:25:47 by tgrange           #+#    #+#             */
/*   Updated: 2017/05/22 16:59:53 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_blocks(t_info **lst)
{
	t_info		*tmp;
	size_t		i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		i += tmp->blocks;
		tmp = tmp->next;
	}
	ft_putstr("total ");
	ft_putnbr(i);
	ft_putchar('\n');
}

void	print_all_specs2(t_info *infos, t_flags flags)
{
	if (infos->date_int + 15778800 < time(NULL))
	{
		ft_putchar(' ');
		ft_putstr_space(infos->date[4]);
	}
	else
		ft_putstr_space(infos->date[3]);
	ft_putstr(infos->name);
	if (flags.p_flag && infos->type == 'd')
		ft_putchar('/');
	if (infos->type == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr(infos->linked_file);
	}
	ft_putchar('\n');
}

void	print_all_specs(t_info *infos, size_t *padding, t_flags flags)
{
	ft_putchar(infos->type);
	ft_putstr(infos->perms);
	ft_print_char(' ', padding[0] - ft_strlen(infos->links) + 1);
	ft_putstr_space(infos->links);
	ft_putstr(infos->author);
	ft_print_char(' ', padding[1] - ft_strlen(infos->author) + 2);
	ft_putstr(infos->grp);
	ft_print_char(' ', padding[2] - ft_strlen(infos->grp) + 2);
	if (padding[4])
	{
		ft_print_char(' ', padding[4] + 1 - ft_strlen(infos->major));
		if (infos->major)
			ft_putstr_space(infos->major);
		else
			ft_putchar(' ');
	}
	ft_print_char(' ', padding[3] - ft_strlen(infos->size));
	ft_putstr_space(infos->size);
	ft_putstr(infos->date[1]);
	ft_print_char(' ', 3 - ft_strlen(infos->date[2]));
	ft_putstr_space(infos->date[2]);
	print_all_specs2(infos, flags);
}

void	display_l_flag(t_info **infos, int printb, t_flags flags)
{
	t_info	*tmp;
	size_t	*padding;

	padding = get_padding(infos);
	tmp = *infos;
	if (printb)
		print_blocks(infos);
	while (tmp)
	{
		print_all_specs(tmp, padding, flags);
		tmp = tmp->next;
	}
}

void	print_dir(t_flags flags, t_info **files, int printb)
{
	t_info		*tmp;

	tmp = *files;
	if (flags.l_flag)
		display_l_flag(files, printb, flags);
	else if (flags.one_flag)
		display_one_flag(files);
	else
		display_basic(files, flags);
}
