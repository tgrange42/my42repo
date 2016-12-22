/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:17:47 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/20 19:09:57 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		main(int nbarg, char **arg)
{
	char	*test;
	int		fd;
	int		i;

 	i = 0;
	(void)nbarg;
	fd = open(arg[1], O_RDONLY);
	while (get_next_line(fd, &test))
	// {
		// ft_putendl("debut get_next_line:");
		ft_putendl(test);
	// }
	close(fd);
	return (0);
}
