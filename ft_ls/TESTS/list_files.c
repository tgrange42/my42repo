#include "../ft_ls.h"

char	*get_path(char *actual_path, char *dir_name)
{
	char	*path;
	int		len;

	len = ft_strlen(actual_path) + ft_strlen(dir_name) + 2;
	if (!(path = (char *)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	path = ft_strcpy(path, actual_path);
	path[ft_strlen(actual_path)] = '/';
	path = ft_strcat(path, dir_name);
	// ft_strdel(&dir_name);
	return (path);
}

void	test_ls(char *name_of_dir)
{
	struct dirent	*list;
	DIR				*stream;

	stream = opendir(name_of_dir);
	while ((list = readdir(stream)) != NULL)
	{
		ft_putendl(get_path(name_of_dir, list->d_name));
	}
	closedir(stream);
}

int		main(int nbarg, char **arg)
{
	if (nbarg == 1)
		test_ls(".");
	else
		test_ls(arg[1]);
	return (0);
}