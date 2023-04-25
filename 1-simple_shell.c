#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - Write a UNIX command line interpreter.
 *
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t ch;
	char *args[BUFFER_SIZE];
	pid_t pid;
	int status;


	while (1)
	{
		int i = 0;

		printf("$ ");
		ch = getline(&line, &len, stdin);

		if (ch == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (strcmp(line, "exit\n") == 0)
		{
			break;
		}

		args[i] = strtok(line, "\n");

		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, "\n");
		}
		args[i] = NULL;

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}

			if (!WIFEXITED(status))
			{
				printf("Child process did not exit normally\n");
			}
		}
	}

	free(line);
	return (0);
}
