#include "holberton.h"
/**
* check_newlines - Checks for newlines in command.
* @av: vector of arguments for the command.
* @idx: Pointer to variable to save the index if found.
* Return: 0 if \n or ; 1 if && and 2 if ||.
*/
short check_newlines(char *av[], short *idx)
{
	short i = 0, retv = -1;

	while (av[i])
	{
		if (*av[i] == '\n' || *av[i] == ';' || !_strcmp(av[i], "&&") ||
			!_strcmp(av[i], "||"))
		{
			switch (*av[i])
			{
				case '&':
					retv = 1;
					break;
				case '|':
					retv = 2;
					break;
				default:
					retv = 0;
					break;
			}
			free(av[i]);
			av[i] = NULL;
			*idx = ++i;
			break;
		}
		i++;
	}
	return (retv);
}
