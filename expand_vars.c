#include "holberton.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void expand_vars(char *av[])
{
	short i, j, k, l = 0, m = 0, replaced = 0, space_flag = 0;
	char varname[100], not_expanded[100], *num2str_res;
	extern int status;

	for (i = 0; av[i]; i++)
	{
		for (j = 0, m = 0, not_expanded[0] = '\0'; av[i][j]; j++)
		{
			if (av[i][j] == ' ')
			{
				space_flag = 1;
				not_expanded[0] = '\0';
				break;
			}
			if (av[i][j] != '$')
			{
				not_expanded[m++] = av[i][j];
				not_expanded[m] = '\0';
			}
			else if (av[i][j + 1] != '\0')
			{
				if (av[i][j + 1] == '?')
				{
					num2str_res = _num2str(status >> 8);
					_strcat(not_expanded, num2str_res);
					m += _strlen(num2str_res);
					free(num2str_res);
					j++;
					continue;
				}
				else if (av[i][j + 1] == '$')
				{
					num2str_res = _num2str(getpid());
					_strcat(not_expanded, num2str_res);
					m += _strlen(num2str_res);
					free(num2str_res);
					j++;
					continue;
				}
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
						not_expanded[0] = '\0';
						_strcat(av[i], environ[k] + l);
						replaced = 1;
						l = 0;
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
					not_expanded[0] = '\0';
				}

			}
		}
		if (not_expanded[0])
		{
			free(av[i]);
			av[i] = malloc(_strlen(not_expanded) + 1);
			_strcpy(av[i], not_expanded);
			not_expanded[0] = '\0';
		}
		
	}
}
char *_num2str(int num)
{
	char *str = malloc(20);
	short i = 0, j;
	
	for (i = 0; num / 10; i++, num /= 10)
		str[i] = num % 10 + '0';
	str[i++] = num % 10 + '0';
	str[i] = '\0';
	for (i = 0, j = _strlen(str) - 1; i < j; i++, j--)
	{
		str[i] += str[j];
		str[j] = str[i] - str[j];
		str[i] -= str[j];
	}
	return (str);
}
