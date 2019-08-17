#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "holberton.h"
#include <string.h>
#include <unistd.h>


/**
* main - Entry point for shell.
* @argc: Argument counter.
* @argv: Arguent vector.
* Return: 0 on success.
*/
int main(int argc, char *argv[])
{
	char *command, *av[10], *token;
	size_t size = 100;
	pid_t child;
	ssize_t getl_res;
	short i, write_err = 0, exit_signal = 0;

	command = malloc(100);
	if (!command)
		return (-1);
	if (argc == 1)
	{
		while (1)
		{
			i = 0;
			write_err = write(STDOUT_FILENO, "Command> ", 9);
			if (write_err == -1)
			{
				perror(argv[0]);
				return (-1);
			}
			getl_res = getline(&command, &size, stdin);
			if (getl_res == EOF)
				break;
			else if (getl_res == -1)
				return (-1);
			if (*command == '\n')
				continue;
			command[_strlen(command) - 1] = '\0';
			token = strtok(command, " ");
			av[i] = malloc(_strlen(token) + 1);
			if (!av[i])
				return (-1);
			_strcpy(av[i++], token);
			if (!_strcmp("exit", av[0]) && (exit_signal = 1))
				break;
			while ((token = strtok(NULL, " ")))
			{
				av[i] = malloc(_strlen(token) + 1);
				if (!av[i])
					return (-1);
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
	if (exit_signal)
		my_exit(strtok(NULL, " "), &command);
	free(command);
	return (0);
}
