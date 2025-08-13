#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - look for files in the current PATH
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;
	char *full_path, *path;
	
	if (ac < 2)
	{
		printf("Usage: %s filename...\n", av[0]);
		return (1);
	}
	/* fetch the PATH variable */
	full_path = getenv("PATH");
	/* use strtok to split path string */
	path = strtok(full_path, ":");
	while (path != NULL)
	{
		printf("path is %s\n", path);
		/* search for files on the current path */
		i = 1;
		while (av[i])
		{
			printf("%s:", strcat(path, av[i]));
			if (stat(strcat(path, av[i]), &st) == 0)
			{
				printf("%s\n", strcat(path, av[i]));
			}
			i++;
		}
	}
	return (0);
}
