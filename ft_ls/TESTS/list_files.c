#include "ft_ls.h"

void	test_ls(char *name_of_dir)
{
	struct dirent	*list;
	DIR				*stream;

	stream = opendir(name_of_dir);
	while ((list = readdir(stream)) != NULL)
	{
		get_stats(list->d_name);
		ft_putendl("");
	}
	closedir(stream);
}

int		main(int nbarg, char **arg)
{
	(void)nbarg;
	test_ls(arg[1]);
	return (0);
}