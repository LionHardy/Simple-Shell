#include <stdio.h>
#include <stdlib.h>


/**
 * exit_builtin - entry point
 *
 * Return: Always 0.
 */

int exit_builtin(void)
{
	printf("Exiting Shell...\n");
	exit(EXIT_SUCCESS);
}
