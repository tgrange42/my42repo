#include <stdlib.h>

int main()
{
	char *test;
	int i = 0;

	while (i < 100000000)
	{
		test = malloc(1024);
		i++;
		free(test);
	}
	return (0);

}