/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstincre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:02:57 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/11 02:16:45 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstincre(t_list *alst, t_list *new)
{
	t_list		*tmp;

	tmp = alst;
	while (alst->next)
	{
		tmp = alst->next;
		alst = tmp;
	}
	if (!(alst->next = (t_list *)malloc(sizeof(t_list))))
		return ;
	if (!(alst->next->content = (void *)malloc(sizeof(new->content) \
					* new->content_size)))
		return ;
	alst->next->content_size = new->content_size;
	alst->next->next = NULL;
	ft_memcpy(alst->next->content, new->content, new->content_size);
}
