#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 2048
#define BUFFER_SIZE_INCREMENT 1

char *leonard_getline(void);

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
		printf("%s", line);
		free(line);
	}

	return (0);
}
