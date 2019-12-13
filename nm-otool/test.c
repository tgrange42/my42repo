#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>

void	nm(char *ptr)
{
	int mn;

	mn = *(int *)ptr;
	if (mn == MH_MAGIC_64)
		handle64(ptr);
}

int		main(int ac, char **av)
{
	struct stat	buf;
	size_t	size;
	char	*tmp;
	int		fd;

	if (ac < 2)
		return (-1);
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putendl_fd("open error", 2);
		return (-1);
	}
	if (fstat(fd, &buf) == -1)
	{
		ft_putendl_fd("lstat error", 2);
		return (-1);
	}
	size = buf.st_size;
	if ((tmp = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		ft_putendl(strerror(errno));
		ft_putendl_fd("mmap error", 2);
		return (-1);
	}
	ft_putendl(tmp);
	return (0);
}
