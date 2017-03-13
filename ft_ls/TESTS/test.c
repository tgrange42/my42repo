#include "ft_ls.h"

void	test_ls(char *name_of_dir)
{
	struct dirent	*list;
	DIR				*stream;

	stream = opendir(name_of_dir);
	while ((list = readdir(stream)) != NULL)
	{
		ft_putnbr(list->d_type);
		ft_putendl("");
		ft_putendl(list->d_name);
	}
	closedir(stream);
}

int		main(int nbarg, char **arg)
{
	(void)nbarg;
	test_ls(arg[1]);
	return (0);
}