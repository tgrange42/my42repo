#include "libft.h"
#include <stdio.h>

int		main(int nbarg, char **arg)
{
	(void)nbarg;
	printf("%s", ft_strnstr(arg[1], arg[2], ft_atoi(arg[3])));
	printf("%s", strnstr(arg[1], arg[2], ft_atoi(arg[3])));
	return (0);
}
