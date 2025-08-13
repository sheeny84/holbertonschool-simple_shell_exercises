#include <stddef.h>
#include <string.h>
#include <stdio.h>

char *_getenv(const char *name)
{
	extern char **environ;
        char *copy, *var;
	unsigned int i;
        
        i = 0;
        while (environ[i] != NULL)
        {
		copy = strdup(environ[i]);
		var = strtok(copy, "=");
	        if (strcmp(name, var) == 0)
	        	return (environ[i]);
	        i++;
	}
	return (NULL);
}

int main()
{
	char *env_var;

	env_var = _getenv("PATH");
	if (env_var == NULL)
		printf("not found\n");
	else
		printf("%s\n", env_var);
	return (0);
}
