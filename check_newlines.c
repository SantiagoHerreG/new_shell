#include "holberton.h"
/**
* check_newlines - Checks for newlines in command.
* @av: vector of arguments for the command.
* @idx: Pointer to variable to save the index if found.
*/
void check_newlines(char *av[], short *idx)
{
	short i = 0;

	while (av[i])
	{
		if (*av[i] == '\n' || *av[i] == ';')
		{
			free(av[i]);
			av[i] = NULL;
			*idx = ++i;
			return;
		}
		i++;
	}
}
