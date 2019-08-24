#include "holberton.h"
#include <linux/limits.h>
#include <stdio.h>
#include <unistd.h>
/**
* set_var - Function to handle the setenv.
* @arg1: Name of the variable to be set.
* @arg2: Value for the variable.
*/
void set_var(char *arg1, char *arg2)
{
	char *new_var, var_to_set[ARG_MAX];
	short i = 0, j = 0;
	extern char *new_envs[];

	if (!arg1 || !arg2)
	{
		write(STDERR_FILENO, "setenv: parameters not found\n", 29);
		return;
	}

	_strcpy(var_to_set, arg1);
	_strcat(var_to_set, "=");

	while (environ[i] && _strncmp(environ[i], var_to_set, _strlen(var_to_set)))
		i++;

	_strcat(var_to_set, arg2);
	if (environ[i])
		_strcpy(environ[i], var_to_set);
	else
	{
		new_var = malloc(100);
		_strcpy(new_var, var_to_set);
		while (new_envs[j])
			j++;
		new_envs[j] = new_var;
		environ[i++] = new_var;
		environ[i] = NULL;
	}
}

/**
 * unset_var - function that unsets an environment variable (locally)
 * @var_name: name of the variable to unset
 * Return: void
 */

void unset_var(char *var_name)
{
	short i = 0;
	char var_to_rm[ARG_MAX];

	if (!var_name)
	{
		write(STDERR_FILENO, "unsetenv: parameter not found\n", 30);
		return;
	}

	_strcpy(var_to_rm, var_name);
	_strcat(var_to_rm, "=");

	while (environ[i] && _strncmp(environ[i], var_to_rm, _strlen(var_to_rm)))
		i++;
	if (!environ[i])
	{
		write(STDERR_FILENO, "unsetenv: Variable not found\n", 29);
		return;
	}
	else
	{
		free(environ[i]);
	}
	while (environ[i])
	{
		environ[i] = environ[i + 1];
		i++;
	}
}
