/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:26:24 by tgrange           #+#    #+#             */
/*   Updated: 2016/11/19 13:06:54 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;
	void		*new_content;

	new_content = NULL;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		content = NULL;
		content_size = 0;
	}
	else
	{
		if (!(new_content = (void *)malloc(sizeof(new_content) * content_size)))
		{
			free(new);
			return (NULL);
		}
		new_content = (void *)content;
	}
	new->content = new_content;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
