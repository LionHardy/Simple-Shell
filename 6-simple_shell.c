#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 2048
#define BUFFER_SIZE_INCREMENT 1

/**
 * leonard_getline - entry point
 *
 * Return: buffer
 */

char *leonard_getline(void)
{
	int a, b =  0;
	size_t size = INITIAL_BUFFER_SIZE;
	size_t increment = BUFFER_SIZE_INCREMENT;
	size_t threshold = 1024;
	char *buffer = malloc(INITIAL_BUFFER_SIZE);

	if (!buffer)
	{
		fprintf(stderr, "Error: Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
	}

	while ((a = getchar()) != EOF && a != '\n')
	{
		char *new_buffer;

		if (b == (int)size - 1)
		{
			size += size < threshold ? size : increment;
			new_buffer = realloc(buffer, size);

			if (!new_buffer)
			{
				fprintf(stderr, "Error: Unable to allocate memory.\n");
				free(buffer);
				exit(EXIT_FAILURE);
			}
			buffer = new_buffer;
		}

		if (a == '\0')
		{
			fprintf(stderr, "Error: Invalid input.\n");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		buffer[b++] = (char) a;
	}

	if (a == EOF && b == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[b] = '\0';
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
		printf("%s", line);
		free(line);
	}

	return (0);
}
