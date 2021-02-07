#include "holberton.h"
/**
* check_builtins - Checks if user entered a builtin.
* @av: Command in tokens.
* @alias: Array of aliases.
* @filename: file with history
* Return: 0 if no builtin, 1 or 2 otherwise.
*/
short check_builtins(char *av[], char *alias[], char *filename)
{
	int alias_ret;

	if (!_strcmp("history", av[0]))
	{
		print_history(filename);
		return (1);
	}
	if (!_strcmp("exit", av[0]))
	{
		my_exit(av, alias, filename);
		return (1);
	}
	if (!_strcmp("cd", av[0]))
	{
		_change_dir(av[1]);
		return (1);
	}
	if (!_strcmp("setenv", av[0]))
	{
		set_var(av[1], av[2]);
		return (1);
	}
	if (!_strcmp("unsetenv", av[0]))
	{
		unset_var(av[1]);
		return (1);
	}
	if (!_strcmp("alias", av[0]))
	{
		alias_ret = print_alias(av, alias);
		return (alias_ret);
	}
	return (0);
}
