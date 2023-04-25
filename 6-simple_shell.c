#include <stdio.h>

/**
 * leonard_getline - entry point
 *
 * Return: buffer
 */

char *leonard_getline(void)
{
	static char buffer[2048];
	static int;

	char c;

	while ((c = getchar()) != EOF && c != '\n')
	{
	buffer[pos++] = c;

	if (pos == sizeof(buffer) - 1)
	{
		buffer[pos] = '\n';
		return (buffer);
	}
	}

	if (c == EOF && pos == 0)
	{
		return (NULL);
	}

	buffer[pos] = '\0';
	pos = 0;
	return (buffer);
}

/**
 * main - Write your own getline function
 *
 * Return: Always 0
 */

int main(void)
{
	char *line;

	while ((line = leonard_getline()) != NULL)
	{
		printf("You entered: %s\n", line);
	}

	return (0);
}
