/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstincre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:02:57 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/18 18:15:15 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstincre(t_list **alst, t_list *new)
{
	t_list		**tmp;

	tmp = alst;
	while ((*tmp)->next)
		*tmp = (*tmp)->next;
	(*tmp)->next = new;
}
