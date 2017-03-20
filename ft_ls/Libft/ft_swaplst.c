/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaplst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:53:47 by tgrange           #+#    #+#             */
/*   Updated: 2017/03/17 17:00:00 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swaplst(t_list *s1, t_list *s2)
{
	ft_swapptr(&s1->content, &s2->content);
	ft_swap((int *)&s1->content_size, (int *)&s2->content_size);
}
