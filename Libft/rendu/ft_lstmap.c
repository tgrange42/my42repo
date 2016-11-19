/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:54:37 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/19 10:40:49 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*reslst;
	t_list		*tmp;
	t_list		*cursor;

	tmp = f(lst);
	cursor = lst;
	if (!cursor)
		return (NULL);
	reslst = ft_lstnew(tmp->content, tmp->content_size);
	if (!reslst)
		return (NULL);
	cursor = cursor->next;
	while (cursor)
	{
		tmp = f(cursor);
		ft_lstincre(&reslst, tmp);
		cursor = cursor->next;
	}
	return (reslst);
}
