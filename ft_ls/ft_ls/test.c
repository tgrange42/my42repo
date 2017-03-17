/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:00:42 by tgrange           #+#    #+#             */
/*   Updated: 2017/03/17 17:19:33 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rev_list(t_list **lst);

int		main(void)
{
	t_list		*test;
	t_list		*lol;
	t_list		*lel;

	lel = ft_lstnew("abc", 3);
	lol = ft_lstnew("cde", 3);
	test = ft_lstnew("bodde", 5);
	ft_lstincre(&test, lol);
	ft_lstincre(&test, lel);
	ft_putendl(test->content);
	ft_putendl(test->next->content);
	ft_putendl(test->next->next->content);
	// rev_list(&test);
	sort_list_alpha(&test);
	ft_putendl(test->content);
	ft_putendl(test->next->content);
	ft_putendl(test->next->next->content);
	return (0);
}
¡