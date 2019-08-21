#include "holberton.h"
/**
* check_builtins - Checks if user entered a builtin.
* @av: Command in tokens.
* @exit_signal: Flag for exit builtin.
* Return: 0 if no builtin, 1 or 2 otherwise.
*/
short check_builtins(char *av[], short *exit_signal)
{
	char *token;

	if (!_strcmp("exit", av[0]))
	{
		*exit_signal = 1;
		free(av[0]);
		return (1);
	}
	if (!_strcmp("cd", av[0]))
	{
		_change_dir(_strtok(NULL, " "));
		free(av[0]);
		return (2);
	}
	if (!_strcmp("setenv", av[0]))
	{
		token = _strtok(NULL, " ");
		set_var(token, _strtok(NULL, " "));
		free(av[0]);
		return (2);
	}
	if (!_strcmp("unsetenv", av[0]))
	{
		unset_var(_strtok(NULL, " "));
		return (2);
	}
	return (0);
}
