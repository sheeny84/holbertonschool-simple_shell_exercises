#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *full_path, *path_copy, *path;
	
	full_path = getenv("PATH");
	path_copy = strdup(full_path);
	path = strtok(path_copy, ":");
	while (path != NULL)
	{
		printf("%s\n", path);
		path = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}
