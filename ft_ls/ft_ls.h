/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:31:31 by tgrange           #+#    #+#             */
/*   Updated: 2017/04/12 02:58:13 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/ioctl.h>
# include <errno.h>

/*
**	Structs
*/

typedef struct		s_flags
{
	int				grand_r_flag;
	int				a_flag;
	int				l_flag;
	int				r_flag;
	int				t_flag;
	int				one_flag;
}					t_flags;

typedef struct		s_winenv
{
	size_t			column;
	size_t			max_len;
	size_t			nb_col;
	size_t			nb_files;
	size_t			nb_lines;
}					t_winenv;

typedef struct		s_info
{
	char			type;
	char			*name;
	char			*path;
	char			*grp;
	char			*author;
	char			*perms;
	char			*size;
	char			*links;
	char			**date;
	size_t			blocks;
	time_t			date_int;
	struct s_info	*next;
}					t_info;

/*
**	time.c
*/

char				**get_time_char(char *name, time_t *int_date);
void				sort_list_time(t_info **lst);

/*
**	error_ls.c
*/

void				exit_error(int type_of_error, char wrong_flag);
void				write_error(char *name_folder);
void				not_file(char **name);

/*
**	flags_ls.c
*/

void				get_multiple_flags(char **argv, t_flags *stock);
void				initialize_struct_flags(t_flags *flags);

/*
**	tools.c
*/

char				*get_path(char *actual_path, char *dir_name);
size_t				get_nb_files(t_info **files);

/*
**	lscore.c
*/

void				ft_opendir(t_flags flags, char *name, t_info *infos, char *pure_name);
t_info				*create_t_info(char *name_file, int type, char *path);
void				get_multiple_arg(char ***argv, t_flags flags);

/*
**	list_ls.c
*/

void				rev_list(t_info **lst);
void				sort_list_alpha(t_info **begin_lst);
void				pushback_t_info(t_info *new, t_info **begin);
void				swap_t_info(t_info *m1, t_info *m2);

/*
**	collect_infos.c
*/

void				collect_infos(t_info **lst);

/*
**	display.c
*/

void				display_it(t_info **files);

/*
**	display2.c
*/

void				print_dir(t_flags flags, t_info **files);
void				display_one_flag(t_info **files);

/*
**	clean_ls.c
*/

void				clean_t_info(t_info **lst, t_flags flags);
void				next_rm(t_info **lst);
void				display_basic(t_info **files);

#endif
