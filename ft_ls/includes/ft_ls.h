/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:31:31 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/12 15:49:31 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <unistd.h>
# include <sys/xattr.h>
# include <stdio.h>

/*
**	Structs
*/

typedef struct		s_flags
{
	int				grand_c_flag;
	int				grand_r_flag;
	int				grand_u_flag;
	int				a_flag;
	int				d_flag;
	int				l_flag;
	int				r_flag;
	int				t_flag;
	int				one_flag;
	int				p_flag;
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
	int				error;
	char			type;
	char			*name;
	char			*path;
	char			*grp;
	char			*author;
	char			*perms;
	char			*major;
	char			*size;
	char			*links;
	char			*linked_file;
	char			**date;
	size_t			blocks;
	time_t			date_int;
	struct s_info	*next;
}					t_info;

/*
**	time.c
*/

void				get_time(t_info *lst, int birth);
void				pushback_t_info_time(t_info *new, t_info **begin);

/*
**	error_ls.c
*/

void				exit_error(int type_of_error, char wrong_flag);
void				write_error(char *name_folder, char *error);
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
void				get_group_author(struct stat buf, t_info *infos);
void				equal_equal(t_info **t1, t_info **t2, t_info **s1,
	t_info **s2);
char				***create_tab_nb(int size, int length);

/*
**	tools2.c
*/

t_info				*tab_to_t_info(char **tab, t_flags flags);
void				del_tabstr(char ***str);

/*
**	lscore.c
*/

void				ft_opendir(t_flags flags, char *name, t_info *infos,
	char *pure_name);
void				get_multiple_arg(char ***argv, t_flags flags);

/*
**	list_ls.c
*/

void				create_t_info(char *name_file, char *path, t_flags flags,
	t_info **begin);
void				rev_list(t_info **lst);
void				swap_t_info(t_info *m1, t_info *m2);

/*
**	collect_infos.c
*/

void				collect_infos(t_info **lst);
char				get_type(struct stat buf);

/*
**	display.c
*/

void				display_it(t_info **files);
void				print_dir(t_flags flags, t_info **files, int printb);

/*
**	display2.c
*/

void				display_one_flag(t_info **files);
void				display_basic(t_info **files, t_flags flags);

/*
**	display3.c
*/

size_t				*get_padding(t_info **infos);

/*
**	clean_ls.c
*/

void				clean_t_info(t_info **lst, t_flags flags);
void				next_rm(t_info **lst);
void				jump_t_info(t_info **lst, char *name);
void				rm_t_info(t_info *lst);
void				clean_lst(t_info **lst);

#endif
