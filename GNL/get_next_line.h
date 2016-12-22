/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:20:10 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/21 22:49:51 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# define BUFF_SIZE 32

/*
**	struct to stock multi fd
*/

typedef struct 		s_gnl
{
	char			buf[BUFF_SIZE];
	int				fd;
	int				i;
	struct s_list	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
#endif
