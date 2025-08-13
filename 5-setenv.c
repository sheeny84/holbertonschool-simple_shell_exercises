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

int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	char *var;
	
	/* search for variable in environment variables */
	var = _getenv(name);
	if (var != NULL) /* i.e. variable already exists */
	{
		strcat(var, value);
	}
	else /* add name and value to environ */
	{
		while (environ[i] != NULL)
		{
			i++;
		}
		snprintf(environ[i], sizeof(environ[i]), "%s=%s", name, value);
	}
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
