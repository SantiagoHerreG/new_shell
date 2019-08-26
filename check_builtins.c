#include "holberton.h"
/**
* check_builtins - Checks if user entered a builtin.
* @av: Command in tokens.
* @exit_signal: Flag for exit builtin.
* @filename: file with history
* Return: 0 if no builtin, 1 or 2 otherwise.
*/
short check_builtins(char *av[], char *alias[], char *filename)
{
	short i = 0;
	int alias_ret;

	if (!_strcmp("history", av[0]))
	{
		while (av[i])
			free(av[i++]);
		print_history(filename);
		return (1);
	}
	if (!_strcmp("exit", av[0]))
	{
		free(filename);
		my_exit(av, alias);
	}
	if (!_strcmp("cd", av[0]))
	{
		_change_dir(av[1]);
		while (av[i])
			free(av[i++]);
		return (1);
	}
	if (!_strcmp("setenv", av[0]))
	{
		set_var(av[1], av[2]);
		while (av[i])
			free(av[i++]);
		return (1);
	}
	if (!_strcmp("unsetenv", av[0]))
	{
		unset_var(av[1]);
		while (av[i])
			free(av[i++]);
		return (1);
	}
	if (!_strcmp("alias", av[0]))
	{
		alias_ret = print_alias(av, alias);
		i = 0;
		while (av[i])
			free(av[i++]);
		return (alias_ret);
	}
	return (0);
}
