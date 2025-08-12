#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - split a string and return an array of each word of the string
 *
 * Return: array of words in the string
 */
char * main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *str_array;

    printf("$ ");

    read = getline(&line, &len, stdin); /* read line from std in */

    if (read == -1)
	    printf("error reading line\n");
    
    str_array = strtok(line, " ");
    while (str_array != NULL)
    {
	    printf("%s\n", str_array);
	    str_array = strtok(NULL, " ");
    }
    free(line);
    return (str_array);
}
