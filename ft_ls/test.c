#include <errno.h>
#include <stdio.h>
#include "ft_ls.h"

int main (int argc, char **argv)
{
	DIR		*stream;

	stream = opendir(argv[1]);
	if (errno == ENOENT)
		ft_putendl("lol");
//	closedir(stream);
    return 0;
}
