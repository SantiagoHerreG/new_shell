#include "holberton.h"
#include <stdio.h>
#include <unistd.h>
/**
 * alias_expansion - function that performs alias expansions
 * @av: array of arguments passed to the program
 * @alias: array of aliases stored in the program
 * Return: void
 */
void alias_expansion(char *av[], char *alias[])
{
	int i = 0, j = 0, eq_len, len;
	char checker[1000], *token, new_args[1000], alias_exp[100][1000];

	if (!alias || !alias[0])
		return;
	_strcpy(checker, alias[i]), token = _strtok(checker, "=");
	while (token && alias[i])
	{
		eq_len = _strlen(token);
		if (!_strcmp(token, av[0]) && alias[i][eq_len] == '=')
			break;
		i++;
		if (alias[i])
			_strcpy(checker, alias[i]), token = _strtok(checker, "=");
	}
	if (!alias[i])
		return;
	token = _strtok(NULL, "="), _strcpy(new_args, token);
	token = _strtok(new_args, " ");
	for (i = 0; token; i++)
	{
		if (token[0] == '\'' && token[1] != '\'')
			_strcpy(alias_exp[i], token + 1);
		else
			_strcpy(alias_exp[i], token);
		token = _strtok(NULL, " ");
	}
	i -= 1;
		len = _strlen(alias_exp[i]);
		alias_exp[i++][len - 1] = '\0';

	for (j = 1; av[j]; j++)
		_strcpy(alias_exp[i++], av[j]), free(av[j]);

	for (j = 0; j < i; j++)
	{
		av[j] = malloc(_strlen(alias_exp[j] + 1));
		_strcpy(av[j], alias_exp[j]);
	}
	av[j] = NULL;
}
