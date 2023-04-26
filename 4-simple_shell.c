#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024


/**
 * main - Implement the exit built-in, that exits the shell
 *
 * Return: Always 0
 */

int exit_builtin(void);

int main(void)
{
	char input[MAX_INPUT];
	int status = 1;

	while (status)
	{
		printf("$ ");
		fgets(input, MAX_INPUT, stdin);

		if (sscanf(input, "%[^\n]%*c", input) != 1)
		{
			fprintf(stderr, "Error reading input\n");
			continue;
		}

		if (strcmp(input, "exit\n") == 0)
		{
			exit_builtin();
			status = 0;
		}
		else
		{
			printf("Unrecognised command: %s", input);
		}
	}

	return (status);
}
