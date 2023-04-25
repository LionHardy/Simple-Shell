#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * main - Write a UNIX command line interpreter.
 *
 * Return: 0
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	int status;
	pid_t pid;
	pid = fork();

	while (1)
	{
		printf("$ ");

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			break;
		}

		buffer[strcspn(buffer, "\n")] = 0;


		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		else if (pid == 0)
		{
			if (execlp(buffer, buffer, NULL) == -1)
			{
				printf("%s: command not found\n", buffer);
				exit(EXIT_FAILURE);
			}
		}

		else
		{
			if (wait(&status) == -1)
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}
	}

	if (errno == EINTR)
	{
		printf("\n");
	}

	return (0);
}
