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
	char *full_path_orig, *full_path, *path;
	char concat_path[1024];

	if (ac < 2)
	{
		printf("Usage: %s filename...\n", av[0]);
		return (1);
	}
	/* fetch the PATH variable and store a copy */
	full_path_orig = getenv("PATH");
	full_path = strdup(full_path_orig);
	/* use strtok to split path string */
	path = strtok(full_path, ":");
	while (path != NULL)
	{
		i = 1;
		/* search for files on the current path */
		while (i < ac)
		{
			snprintf(concat_path, sizeof(concat_path), "%s/%s", path, av[i]);
			if (stat(concat_path, &st) == 0)
			{
				printf("%s\n", concat_path);
			}
			i++;
		}
		path = strtok(NULL, ":");
	}
	return (0);
}
