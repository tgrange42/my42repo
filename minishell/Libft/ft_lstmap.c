/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:54:37 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/23 18:05:56 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*res;
	t_list		*first;

	if (!lst)
		return (NULL);
	first = f(lst);
	if (lst->next == NULL)
		return (first);
	if (lst->next)
		res = first;
	while (lst->next)
	{
		lst = lst->next;
		res->next = f(lst);
		if (!res->next)
			return (NULL);
		res = res->next;
	}
	return (first);
}
