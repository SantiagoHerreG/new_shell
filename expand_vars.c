#include "holberton.h"
void expand_vars(char *av[])
{
	short i, j, k, l = 0, m = 0, replaced = 0, space_flag = 0;
	char varname[100], not_expanded[100];

	for (i = 0; av[i]; i++)
	{
		for (j = 0, m = 0, not_expanded[0] = '\0'; av[i][j]; j++)
		{
			if (av[i][j] == ' ')
			{
				space_flag = 1;
				break;
			}
			if (av[i][j] != '$')
			{
				not_expanded[m++] = av[i][j];
				not_expanded[m] = '\0';
			}
			else if (av[i][j + 1] != '\0')
			{
				for (k = j + 1; av[i][k]; k++)
				{
					if (av[i][k] == ' ')
					{
						space_flag = 1;
						break;
					}
					varname[l++] = av[i][k];
				}
				if (space_flag)
				{
					space_flag = 0;
					break;
				}
				varname[l++] = '=';
				for (k = 0; environ[k]; k++)
				{
					if (!_strncmp(varname, environ[k], l))
					{
						free(av[i]);
						av[i] = malloc(_strlen(not_expanded) + _strlen(environ[k] + l) + 1);
						_strcpy(av[i], not_expanded);
						_strcat(av[i], environ[k] + l);
						replaced = 1;
						break;
					}
				}
				if (replaced)
				{
					replaced = 0;
					break;
				}
				else
				{
					free(av[i]);
					av[i] = malloc(_strlen(not_expanded) + 1);
					_strcpy(av[i], not_expanded);
				}

			}
		}
		
		if (space_flag)
			continue;
	}
}
