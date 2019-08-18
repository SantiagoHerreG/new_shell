#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "holberton.h"
#include <string.h>
#include <unistd.h>
/**
* get_input - Prints prompt and gets input from user.
* @prog_name: Name of the program executed.
* @command: String where input will be saved.
* Return: Result of the getline funcion.
*/
short get_input(char *prog_name, char *command)
{
	short getl_res, write_err;
	size_t size = 100;

	write_err = write(STDOUT_FILENO, "Command> ", 9);
	if (write_err == -1)
	{
		perror(prog_name);
		free(command);
		exit(-1);
	}
	getl_res = getline(&command, &size, stdin);
	return (getl_res);
}
/**
* tokenize - Converts command into tokens.
* @command: Command to convert.
* @av: Vector of pointers to store the tokens.
* @exit_signal: Flag for the exit builtin.
* Return: 1 in case of exit signal, 0 otherwise.
*/
short tokenize(char *command, char *av[], short *exit_signal)
{
	char *token;
	short i = 0;

	token = strtok(command, " ");
	av[i] = malloc(_strlen(token) + 1);
	if (!av[i])
	{
		free(command);
		exit(-1);
	}
	_strcpy(av[i++], token);
	if (!_strcmp("exit", av[0]))
	{
		*exit_signal = 1;
		free(av[0]);
		return (1);
	}
	while ((token = strtok(NULL, " ")))
	{
		av[i] = malloc(_strlen(token) + 1);
		if (!av[i])
		{
			free(command);
			for (--i; i >= 0; i--)
				free(av[i]);
			exit(-1);
		}
		_strcpy(av[i++], token);
	}
	av[i] = NULL;
	return (0);
}
/**
* exec_command - Executes the command.
* @command: Command given by the user.
* @av: Tokenized command.
* @prog_name: Name of the program.
*/
void exec_command(char *command, char *av[], char *prog_name)
{
	pid_t child;
	short i;

	child = fork();
	if (!child)
	{
		execve(av[0], av, NULL);
		perror(prog_name);
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(command);
		_exit(1);
	}
	else
	{
		wait(NULL);
		for (i = 0; av[i]; i++)
			free(av[i]);
	}
}
/**
* main - Entry point for shell.
* @argc: Argument counter.
* @argv: Arguent vector.
* Return: 0 on success.
*/
int main(int argc, char *argv[])
{
	char *command, *av[10];
	short exit_signal = 0, getl_res;

	signal(SIGINT, SIG_IGN);
	command = malloc(100);
	if (!command)
		return (-1);
	if (argc == 1)
	{
		while (1)
		{
			getl_res = get_input(argv[0], command);
			if (getl_res == EOF)
				break;
			if (*command == '\n')
				continue;
			command[_strlen(command) - 1] = '\0';
			if (tokenize(command, av, &exit_signal))
				break;
			exec_command(command, av, argv[0]);
		}
	}
	if (exit_signal)
		my_exit(strtok(NULL, " "), &command);
	free(command);
	return (0);
}
