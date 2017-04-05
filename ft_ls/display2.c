/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:57:30 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/05 19:32:08 by tgrange          ###   ########.fr       */
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
	// ft_putendl("");
	// ft_putnbr(i);
	// ft_putendl("");
	while (l < i)
	{
		l++;
		tmp = tmp->next;
	}
	ft_putstr(tmp->name);
	ft_print_char(' ', wenv.max_len - ft_strlen(tmp->name) + 1);
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
			// ft_putbegl("l =");
			// ft_putnbr(l);
			// ft_putbegl("nb_col =");
			// ft_putnbr(wenv.nb_col);
			// ft_putbegl("i =");
			// ft_putnbr(i);
			// ft_putendl("");
			print_name_t_info(files, i % wenv.nb_col + l * wenv.nb_lines, wenv);
			l++;
		}
		l = 0;
		ft_putchar('\n');
		i++;
	}
}

// void	adjust_wenv(t_winenv *wenv)
// {
// }

void	display_basic(t_info **files)
{
	struct winsize	w;
	t_winenv		win_env;

	win_env.nb_files = get_nb_files(files);
	win_env.max_len = get_max_strlen(files);
	ioctl(0, TIOCGWINSZ, &w);
	win_env.column = w.ws_col;
	win_env.nb_col = (win_env.column - 1) / (win_env.max_len + 1);
	win_env.nb_lines = win_env.nb_files / win_env.nb_col;
	ft_putstr("largueur = ");
	ft_putnbr(win_env.column);
	ft_putbegl("max_len = ");
	ft_putnbr(win_env.max_len);
	ft_putbegl("nb_col = ");
	ft_putnbr(win_env.nb_col);
	ft_putbegl("nb_lines = ");
	ft_putnbr(win_env.nb_lines);
	ft_putbegl("nb_files = ");
	ft_putnbr(win_env.nb_files);
	ft_putendl("");
	// if (win_env.nb_col == 7)
	// 	win_env.nb_col = 6;
	// adjust_wenv(&win_env);
	// win_env.nb_lines--;
	while (win_env.nb_files % win_env.nb_col >= win_env.nb_lines)
	{
		win_env.nb_lines++;
		win_env.nb_col--;
	}
	ft_putstr("largueur = ");
	ft_putnbr(win_env.column);
	ft_putbegl("max_len = ");
	ft_putnbr(win_env.max_len);
	ft_putbegl("nb_col = ");
	ft_putnbr(win_env.nb_col);
	ft_putbegl("nb_lines = ");
	ft_putnbr(win_env.nb_lines);
	ft_putbegl("nb_files = ");
	ft_putnbr(win_env.nb_files);
	ft_putendl("");
	print_basic_padding(win_env, files);
}
