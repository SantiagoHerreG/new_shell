#include "holberton.h"
#include <stdio.h>
#include <unistd.h>


void alias_expansion(char *av[], char *alias[])
{
       int i = 0, j = 0, eq_len, len;
       char checker[1000], *token, new_args[1000], alias_exp[100][1000];

	if (!alias || !alias[0])
		return;
	_strcpy(checker, alias[i]);
	token = _strtok(checker, "=");
       while (token)
       {
               eq_len = _strlen(token);
               if (!_strcmp(token, av[0]) && alias[i][eq_len] == '=')
                       break;
               i++;
		if (alias[i])
		{
			_strcpy(checker, alias[i]);
			token = _strtok(checker, "=");
		}
		else
			break;
       }
       if (!alias[i])
               return;
	write(1, "alias found", 11);

	printf("alias %s\n", alias[i]);

       token = _strtok(NULL, "=");
	_strcpy(new_args, token);

	i = 0;
	while ((token = _strtok(new_args, " ")))
	{
	       if (token[0] == '\'' && token[1] != '\'')
			_strcpy(alias_exp[i++], token + 1);
		else
			_strcpy(alias_exp[i++], token);
	}

	i -= 1;
		len = _strlen(alias_exp[i]);
 		alias_exp[i][len - 1] = '\0';

	j = 0;
	i += 1;
	while (av[j])
	{
		_strcpy(alias_exp[i++], av[j]);
		free(av[j]);
		j++;
	}

	j = 0;

	for (; j <= i; j++)
	{
		av[j] = malloc(_strlen(alias_exp[j] + 1));
		_strcpy(av[j], alias_exp[j]);
	}
	av[j] = NULL;
}
