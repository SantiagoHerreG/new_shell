#include "holberton.h"
#include <stdlib.h>
/**
 * my_exit - function that exits the program with specified state
 * @exit_status: pointer to the argument of exit
 * Return: void
 */

void my_exit(char *av[], char *alias[])
{
	int i = 0, j = 0;

	while (alias[i])
		free(alias[i++]);

	if (av[1])
	{
		i = _atoi(av[1]);
		while (av[j])
			free(av[j++]);
		exit(i);
	}
	else
	{
		while (av[j])
			free(av[j++]);
		exit(0);
	}
}
