#include <stdio.h>

/**
 * main - print the addresses of env and environ
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	extern char **environ;
	
	printf("Address of env is %d and environ is %d\n", **env, **environ);
	return (0);
}
