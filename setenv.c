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
	short i = 0;

	if (!arg1 || !arg2)
	{
		write(STDOUT_FILENO, "setenv: parameters not found\n", 29);
		return;
	}

	_strcpy(var_to_set, arg1);
	_strcat(var_to_set, "=");

	new_var = malloc(ARG_MAX);
	if (!new_var)
		exit(-1);

	while (environ[i] && _strncmp(environ[i], var_to_set, _strlen(var_to_set)))
		i++;

	new_var[0] = '\0';
	_strcat(new_var, arg1);
	_strcat(new_var, "=");
	_strcat(new_var, arg2);
	if (environ[i])
		_strcpy(environ[i], new_var);
	else
	{
		environ[i++] = new_var;
		environ[i] = NULL;
	}
	free(new_var);
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
		write(STDOUT_FILENO, "unsetenv: parameter not found\n", 29);
		return;
	}

	_strcpy(var_to_rm, var_name);
	_strcat(var_to_rm, "=");

	while (environ[i] && _strncmp(environ[i], var_to_rm, _strlen(var_to_rm)))
		i++;
	if (!environ[i])
	{
		write(STDOUT_FILENO, "unsetenv: Variable not found\n", 19);
		return;
	}
	while (environ[i])
	{
		environ[i] = environ[i + 1];
		i++;
	}
}
