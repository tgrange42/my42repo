/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:25:47 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/13 06:59:25 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	*get_padding(t_info **infos)
{
	t_info		*tmp;
	size_t		*ret;

	if (!(ret = (size_t *)ft_memalloc(sizeof(size_t) * 4)))
		return (NULL);
	tmp = *infos;
	while (tmp)
	{
		if (ft_strlen(tmp->links) > ret[0])
			ret[0] = ft_strlen(tmp->links);
		if (ft_strlen(tmp->author) > ret[1])
			ret[1] = ft_strlen(tmp->author);
		if (ft_strlen(tmp->grp) > ret[2])
			ret[2] = ft_strlen(tmp->grp);
		if (ft_strlen(tmp->size) > ret[3])
			ret[3] = ft_strlen(tmp->size);
		tmp = tmp->next;
	}
	return (ret);
}

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
	ft_print_char(' ', padding[3] - ft_strlen(infos->size));
	ft_putstr_space(infos->size);
	ft_putstr(infos->date[1]);
	ft_print_char(' ', 3 - ft_strlen(infos->date[2]));
	ft_putstr_space(infos->date[2]);
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
