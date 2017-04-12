/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:57:30 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/12 03:11:53 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_one_flag(t_info **files)
{
	t_info	*tmp;

	tmp = *files;
	while (tmp)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

size_t	get_max_strlen(t_info **files)
{
	t_info	*tmp;
	size_t	max;

	max = 0;
	tmp = *files;
	while (tmp)
	{
		if (ft_strlen(tmp->name) > max)
			max = ft_strlen(tmp->name);
		tmp = tmp->next;
	}
	return (max);
}

void	print_name_t_info(t_info **files, size_t i, t_winenv wenv)
{
	size_t	l;
	t_info	*tmp;

	tmp = *files;
	l = 0;
	while (l < i && tmp)
	{
		l++;
		tmp = tmp->next;
	}
	if (tmp)
	{
		ft_putstr(tmp->name);
		ft_print_char(' ', wenv.max_len - ft_strlen(tmp->name) + 1);
	}
}

void	print_basic_padding(t_winenv wenv, t_info **files)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (i < wenv.nb_lines)
	{
		while (l < wenv.nb_col)
		{
			print_name_t_info(files, i % wenv.nb_lines + l * wenv.nb_lines, wenv);
			l++;
		}
		l = 0;
		ft_putchar('\n');
		i++;
	}
}

void	display_basic(t_info **files)
{
	struct winsize	w;
	t_winenv		win_env;
	int				i;
	int				l;

	win_env.nb_files = get_nb_files(files);
	win_env.max_len = get_max_strlen(files);
	ioctl(0, TIOCGWINSZ, &w);
	win_env.column = w.ws_col;
	win_env.nb_col = (win_env.column) / (win_env.max_len + 1);
	i = win_env.nb_files / win_env.nb_col;
	l = win_env.nb_files % win_env.nb_col;
	win_env.nb_lines = i + (l ? 1 : 0);
	print_basic_padding(win_env, files);
}
