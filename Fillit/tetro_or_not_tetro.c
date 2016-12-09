/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_or_not_tetro.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 23:28:51 by tgrange           #+#    #+#             */
/*   Updated: 2016/12/06 16:25:16 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_the_good_one2(int which)
{
	if (which == 13)
		return (".#..\n.#..\n##..\n....\n");
	if (which == 14)
		return ("#...\n###.\n....\n....\n");
	if (which == 15)
		return ("##..\n#...\n#...\n....\n");
	if (which == 16)
		return ("##..\n.##.\n....\n....\n");
	if (which == 17)
		return (".#..\n##..\n#...\n....\n");
	if (which == 18)
		return (".##.\n##..\n....\n....\n");
	return ("#...\n##..\n.#..\n....\n");
}

char	*get_the_good_one(int which)
{
	if (which == 1)
		return ("####\n....\n....\n....\n");
	if (which == 2)
		return ("#...\n#...\n#...\n#...\n");
	if (which == 3)
		return ("##..\n##..\n....\n....\n");
	if (which == 4)
		return ("#...\n##..\n#...\n....\n");
	if (which == 5)
		return ("###.\n.#..\n....\n....\n");
	if (which == 6)
		return (".#..\n##..\n.#..\n....\n");
	if (which == 7)
		return (".#..\n###.\n....\n....\n");
	if (which == 8)
		return ("###.\n#...\n....\n....\n");
	if (which == 9)
		return ("##..\n.#..\n.#..\n....\n");
	if (which == 10)
		return ("..#.\n###.\n....\n....\n");
	if (which == 11)
		return ("#...\n#...\n##..\n....\n");
	if (which == 12)
		return ("###.\n..#.\n....\n....\n");
	return (get_the_good_one2(which));
}

int		tetro_or_not_tetro(char **tetro)
{
	int		i;
	int		which_one;

	which_one = 0;
	i = 0;
	while (tetro[i])
	{
		if (!(which_one = tetro_test(tetro[i])))
			return (0);
		tetro[i] = ft_strcpy(tetro[i], get_the_good_one(which_one));
		i++;
	}
	return (1);
}
