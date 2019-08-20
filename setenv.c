#include "holberton.h"
/**
* set_unset_var - Function to handle the setenv.
* @arg1: Name of the variable to be set.
* @arg2: Value for the variable.
*/
void set_unset_var(char *arg1, char *arg2)
{
	char *new_var = malloc(1000);
	int i = 0;

	while (environ[i] && _strncmp(environ[i], arg1, _strlen(arg1)))
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
}
