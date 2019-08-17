#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "holberton.h"
/**
* main - Entry point for shell.
* @argc: Argument counter.
* @argv: Arguent vector.
* Return: 0 on success.
*/
int main(int argc, char *argv[])
{
	char *command = malloc(100), *av[2];
	size_t size = 100;
	pid_t child;
	ssize_t getl_res;

	if (argc == 1)
	{
		while (1)
		{
			write(STDOUT_FILENO, "Command> ", 9);
			getl_res = getline(&command, &size, stdin);
			if (getl_res == EOF)
				break;
			if (*command == '\n')
				continue;
			command[_strlen(command) - 1] = '\0';
			av[0] = command;
			av[1] = NULL;
			child = fork();
			if (!child)
			{
				execve(command, av, NULL);
				perror(argv[0]);
				free(command);
				exit(1);
			}
			else
				wait(NULL);
		}
	}
	free(command);
	return (0);
}
