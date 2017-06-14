#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	pid_t	father;
	char	*buf;

	father = fork();
	if (father > 0)
	{
		printf("LMAO\n");
		wait();
	}
	if (!father)
	{
		execve("/bin/ls", av, NULL);
	}
	printf("LOL\n");
	return (0);
}