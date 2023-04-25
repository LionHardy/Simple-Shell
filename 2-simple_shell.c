#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define MAX_ARGS 10

/**
 * main - simple shell that can handle command lines with arguments
 *
 * Return: Always 0
 */

int main(void)
{
	char line[MAX_LINE];
	int should_run = 1;

	char *token = NULL;

	char *args[MAX_ARGS] = {NULL};

	int i = 0;

	while (should_run)
	{
		printf("shell> ");
		fflush(stdout);

		int i = 0;

		fgets(line, MAX_LINE, stdin);
		*(line + strlen(line) - 1) = '\0';
		token = strtok(line, " ");

		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}

		args[i] = NULL;

		if (strcmp(args[0], "exit") == 0)
		{
			should_run = 0;
		}

		else
		{
			pid_t pid = fork();


			if (pid < 0)
			{
				fprintf(stderr, "fork failed\n");
				exit(1);
			}

			else if (pid == 0)
			{
				execvp(args[0], args);
				fprintf(stderr, "execution failed\n");
				exit(1);
			}

			else
			{
				wait(NULL);
			}
		}
	}

	return (0);
}

