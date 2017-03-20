/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:31:31 by tgrange           #+#    #+#             */
/*   Updated: 2017/03/20 14:51:13 by tgrange          ###   ########.fr       */
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

/*
**	Structs
*/

typedef struct		s_flags
{
	int				R_flag;
	int				a_flag;
	int				l_flag;
	int				r_flag;
	int				t_flag;
}					t_flags;

typedef struct		s_info
{
	char			type;
	char			*name;
	char			**date;
	char			*grp;
	char			*author;
	char			*perms;
	int				*date_int;
	size_t			size;
	size_t			links;
	struct s_info	*next;
}					t_info;

/*
**	ft_ls.c
*/	

/*
**	error_ls.c
*/

void				exit_error(int type_of_error, char wrong_flag);

/*
**	flags_ls.c
*/

void				get_multiple_flags(char **argv, t_flags *stock);
void				get_flags(t_flags *stock, char *flags);
void				initialize_struct_flags(t_flags *flags);
/*
**	path.c
*/

char				*get_path(char *actual_path, char *dir_name);

/*
**	lscore.c
*/

void				ft_opendir(t_flags flags, char *name);
t_list				*get_files_names(char *path, t_flags flags);
void				get_multiple_arg(char **argv, t_flags flags);

/*
**	list_ls.c
*/

void				rev_list(t_list **lst);
void				sort_list_alpha(t_list **begin_lst);


#endif
