#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - read a line of text from std in and print it
 *
 * Return: Always 0.
 */
int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("$ ");

    read = getline(&line, &len, stdin); /* read line from std in */

    if (read != -1)
	    printf("%s", line);
    else
	    printf("error reading line\n");
    
    free(line);
    return (0);
}
