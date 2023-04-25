#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void builtin_env(void)
{
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}

	return (0);
}

/**
 * main - Implement the env built-in, that prints the current environment
 *
 * Return: Always 0
 */

int main(void)
{
	while (1)
	{
		char input[1024];

		printf("$ ");

		fgets(input, 1024, stdin);

		input[strcspn(input, "\n")] = '\0';

		char *args[64];
		char *token = strtok(input, " ");
		int i = 0;

		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (strcmp(args[0], "env") == 0)
		{
			builtin_env();
			continue;
		}
	}

	return (0);
}
