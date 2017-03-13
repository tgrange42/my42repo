/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:31:31 by tgrange           #+#    #+#             */
/*   Updated: 2017/03/10 17:00:01 by tgrange          ###   ########.fr       */
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
	int			R_flag;
	int			a_flag;
	int			l_flag;
	int			r_flag;
	int			t_flag;
}					t_flags;

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

#endif
