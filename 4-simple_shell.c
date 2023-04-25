#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024

int exit_builtin(void);

/**
 * main - Implement the exit built-in, that exits the shell
 *
 * Return: Always 0
 */

int main(void)
{
	char input[MAX_INPUT];
	int status = 1;

	while (status)
	{
		printf("$ ");
		fgets(input, MAX_INPUT, stdin);

		if (strcmp(input, "exit\n") == 0)
		{
			status = exit_builtin();
		}
		else
		{
		}
	}

	return (status);
}
