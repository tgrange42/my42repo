/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:19:25 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/27 17:54:41 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pwd(void)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, PATH_MAX);
	ft_putendl(buf);
	ft_strdel(&buf);
}
