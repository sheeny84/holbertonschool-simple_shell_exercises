#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - super simple shell that can run commands with their full path,
 * without any arguments
 *
 * Return: Always 0.
 */
int main(void)
{
        char *line;
        size_t len = 0;
        ssize_t read;
        pid_t child_pid;
        char *argv[] = {"", NULL};
        int status;

        while(1) // infinite loop
        {
                /* print prompt */
                printf("#cisfun$ ");
                /* read a line in from stdin */
                read = getline(&line, &len, stdin);
                if (read == -1) // handle error
                        printf("error reading line\n");
                else // i.e. read was successfu;l
                {
			/* replace new line with null byte */
			line[read - 1] = '\0';
                        argv[0] = line;
                }
                /* create child fork */
                child_pid = fork();
                /* execute program if we are the child process */
                if (child_pid == 0)
                {
                        if (execve(argv[0], argv, NULL) == -1)
                                perror("Error:");
                }
                else /* wait for child to complete */
                        wait(&status);
        }
    return (0);
}
