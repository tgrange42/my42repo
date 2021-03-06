/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:26:24 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/23 11:22:53 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		content_size = 0;
		new->content = NULL;
	}
	else
	{
		if (!(new->content = (void *)malloc(sizeof(content) * content_size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size + 1);
	}
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
