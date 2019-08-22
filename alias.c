#include "holberton.h"
#include <linux/limits.h>
#include <stdio.h>
#include <unistd.h>

int print_alias(char *av[], char*alias[])
{
	int i = 0, j = 1, len = 0, flag = 0, setalias_res = 0, eq_len = 0;
	char alias_name[ARG_MAX]; /*alias_value[ARG_MAX];*/

	if (!av[j])
	{
		while (alias[i])
		{
			len = _strlen(alias[i]);
			write(STDOUT_FILENO, alias[i], len);
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
	else
	{
	while (av[j])
	{
		while (alias[i])
		{
			_strcpy(alias_name, alias[i]);
			_strtok(alias_name, "=");
			eq_len = _strlen(alias_name);
			if (!_strcmp(alias_name, av[j]) && alias[i][eq_len] == '=')
			{
				len = _strlen(alias[i]);
				write(STDOUT_FILENO, alias[i], len);
				write(STDOUT_FILENO, "\n", 1);
				flag++;
			}
			i++;
		}
		if (!flag)
		{
			setalias_res = set_alias(av[j], alias);
			if (!setalias_res)
			{
				len = _strlen(av[j]);
				write(STDOUT_FILENO, av[j], len);	
				write(STDOUT_FILENO, ": Not found\n", 12);
			}
		}
		flag = 0;
		j++;
		i = 0;
	}
	}
	return (2);
}

short set_alias(char *new_alias, char *alias[])
{
	int i = 0, len = 0;
	char new_alias_cpy[ARG_MAX], *alias_name, *alias_value, al_cpy[ARG_MAX];
	char old_alias_cpy[ARG_MAX];

	while (new_alias[i])
	{
		if (new_alias[i] == '=')
			break;
		i++;
	}
	if (new_alias[i] == '\0')
		return (0);

	_strcpy(al_cpy, new_alias);
	alias_name = _strtok(al_cpy, "=");
	alias_value = _strtok(NULL, "=");

	if (!alias_value)
		alias_value = "''";
	_strcpy(new_alias_cpy, alias_name);
	_strcat(new_alias_cpy, "=");
	if (alias_value[0] != '\'')
		_strcat(new_alias_cpy, "'");

	len = _strlen(alias_value);
	_strcat(new_alias_cpy, alias_value);

	if (alias_value[len - 1] != '\'')
		_strcat(new_alias_cpy, "'");
	
	i = 0;
	while (alias[i])
	{
		_strcpy(old_alias_cpy, alias[i]);
		_strtok(old_alias_cpy, "=");
		if (!_strcmp(old_alias_cpy, alias_name))
		{
			_strcpy(alias[i], new_alias_cpy);
			return (1);
		}
		i++;
	}

	alias[i] = malloc(ARG_MAX);
	if (!alias[i])
		exit(-1);

	_strcpy(alias[i++], new_alias_cpy);
	alias[i + 1] = NULL;
	return (1);
}
