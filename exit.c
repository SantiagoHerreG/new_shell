#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * my_exit - function that exits the program with specified state
 * @av: pointer to the array of arguments
 * @alias: array of aliases
 * @filename: Memory used on history.
 * Return: void
 */

void my_exit(char *av[], char *alias[], char *filename)
{
	int i = 0, j = 0;

	if (av[1])
	{
		i = _atoi(av[1]);
		if (i < 0 || *av[1] < 49 || *av[1] > 57)
		{
			write(STDERR_FILENO, ":Illegal number:\n", 17);
		}
		else
		{
			while (alias[j])
				free(alias[j++]);
			j = 0;
			while (new_envs[j])
				free(new_envs[j++]);
			j = 0;
			while (av[j])
				free(av[j++]);
			free(filename);
			exit(i);
		}
	}
	else
	{
		while (alias[i])
			free(alias[i++]);
		i = 0;
		while (new_envs[i])
			free(new_envs[i++]);
		while (av[j])
			free(av[j++]);
		free(filename);
		exit(0);
	}
}
