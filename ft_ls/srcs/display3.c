/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:25:04 by tgrange           #+#    #+#             */
/*   Updated: 2017/06/06 16:56:11 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

size_t	*get_padding(t_info **infos)
{
	t_info		*tmp;
	size_t		*ret;

	if (!(ret = (size_t *)ft_memalloc(sizeof(size_t) * 5)))
		return (NULL);
	tmp = *infos;
	while (tmp)
	{
		if (ft_strlen(tmp->links) > ret[0])
			ret[0] = ft_strlen(tmp->links);
		if (ft_strlen(tmp->author) > ret[1])
			ret[1] = ft_strlen(tmp->author);
		if (ft_strlen(tmp->grp) > ret[2])
			ret[2] = ft_strlen(tmp->grp);
		if (ft_strlen(tmp->size) > ret[3])
			ret[3] = ft_strlen(tmp->size);
		if (tmp->major && ft_strlen(tmp->major) > ret[4])
			ret[4] = ft_strlen(tmp->major);
		tmp = tmp->next;
	}
	return (ret);
}
