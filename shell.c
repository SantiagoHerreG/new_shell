#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "holberton.h"
#include <string.h>
/**
* main - Entry point for shell.
* @argc: Argument counter.
* @argv: Arguent vector.
* Return: 0 on success.
*/
int main(int argc, char *argv[])
{
	char *command = malloc(100), *av[10], *token;
	size_t size = 100;
	pid_t child;
	ssize_t getl_res;
	short i;

	if (argc == 1)
	{
		while (1)
		{
			i = 0;
			write(STDOUT_FILENO, "Command> ", 9);
			getl_res = getline(&command, &size, stdin);
			if (getl_res == EOF)
				break;
			if (*command == '\n')
				continue;
			command[_strlen(command) - 1] = '\0';
			token = strtok(command, " ");
			av[i] = malloc(_strlen(token) + 1);
			_strcpy(av[i++], token);
			while ((token = strtok(NULL, " ")))
			{
				av[i] = malloc(_strlen(token) + 1);
				_strcpy(av[i++], token);
			}
			av[i] = NULL;
			child = fork();
			if (!child)
			{
				execve(av[0], av, NULL);
				perror(argv[0]);
				_exit(1);
			}
			else
			{
				wait(NULL);
				for (--i; i >= 0; i--)
					free(av[i]);
			}
		}
	}
	free(command);
	return (0);
}
