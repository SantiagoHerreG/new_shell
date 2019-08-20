#include <string.h>
#include "holberton.h"
/**
* getenvtok - Get environment variable as tokens.
* @envp: Environment variables.
* @var: Variable to find.
* @token: Array to save the tokens.
* Return: String that must be free'd.
*/
char *getenvtok(char *envp[], char *var, char *token[])
{
	short i = 0;
	char *path_str = NULL;

	while (_strncmp(envp[i], var, _strlen(var)))
		i++;
	path_str = malloc(_strlen(envp[i]) + 1);
	if (!path_str)
		exit(-1);
	_strcpy(path_str, envp[i]);
	i = 0;
	strtok(path_str, "=");
	while ((token[i++] = strtok(NULL, ":")))
		;
	return (path_str);
}
