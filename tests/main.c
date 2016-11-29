#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../libft/libft.h"

int		main(int nbarg, char **arg)
{
	int		fd;
	char	buf[6];

	(void)nbarg;
	fd = open(arg[1], O_RDONLY);
	read(fd, &buf, 6);
	ft_putendl(buf);
	close(fd);
	if (buf[4] == '\0')
		ft_putchar('R');
	return (0);
}
