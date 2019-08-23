#include "holberton.h"
#include <stdlib.h>
/**
 * my_exit - function that exits the program with specified state
 * @exit_status: pointer to the argument of exit
 * Return: void
 */

void my_exit(char *exit_status, char *alias[])
{
	int i;

	while (alias[i])
		free(alias[i++]);

	if (exit_status)
	{
		i = _atoi(exit_status);
		exit(i);
	}
	else
	{
		exit(0);
	}
}
