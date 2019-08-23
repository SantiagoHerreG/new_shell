#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "holberton.h"
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include <limits.h>
/**
* get_input - Prints prompt and gets input from user.
* @prog_name: Name of the program executed.
* @command: String where input will be saved.
* Return: Result of the getline funcion.
*/
short get_input(char *prog_name, char **command)
{
	short getl_res, write_err;
	int size = ARG_MAX;

	write_err = write(STDOUT_FILENO, "Command> ", 9);
	if (write_err == -1)
	{
		perror(prog_name);
		free(command);
		exit(-1);
	}
	getl_res = _getline(command, &size, STDIN_FILENO);
	return (getl_res);
}
/**
* tokenize - Converts command into tokens.
* @command: Command to convert.
* @av: Vector of pointers to store the tokens.
* @exit_signal: Flag for the exit builtin.
* Return: 1 in case of exit signal, 0 otherwise.
*/
short tokenize(char *command, char *av[], short *exit_signal, char *alias[])
{
	char *token;
	short i = 0, builtin = 0;
	int alias_ret = 0;

	token = _strtok(command, " ");
	av[i] = malloc(_strlen(token) + 1);
	if (!av[i])
		free(command), exit(-1);
	_strcpy(av[i++], token);
	builtin = check_builtins(av, exit_signal);
	if (builtin)
		return (builtin);
	while ((token = _strtok(NULL, " ")))
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

	if (!_strcmp("alias", av[0]))
	{
			alias_ret = print_alias(av, alias);
			if (alias_ret)
			{
				i = 0;
				while (av[i])
					free(av[i++]);
				return (alias_ret);
			}
	}
	return (0);
}
/**
* exec_command - Executes the command.
* @command: Command given by the user.
* @av: Tokenized command.
* @prog_name: Name of the program.
* @envp: Environment for the program.
*/
void exec_command(char *command, char *av[], char *prog_name, char *envp[])
{
	pid_t child;
	short i = 0, idx = -1, checks = -1;
	char *token[100], *full_comm = NULL, *path_str = NULL;
	int status;

	checks = check_newlines(av, &idx);
	path_str = getenvtok(envp, "PATH", token);
	child = fork();
	if (!child)
	{
		do {
			full_comm = malloc(_strlen(token[i]) + _strlen(av[0]) + 2);
			if (!full_comm)
				exit(-1);
			_strcpy(full_comm, token[i]);
			_strcat(full_comm, "/");
			execve(_strcat(full_comm, av[0]), av, envp);
			free(full_comm);
			i++;
		} while (token[i]);
		execve(av[0], av, envp);
		perror(prog_name);
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(path_str);
		_exit(1);
	}
	else
	{
		wait(&status);
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(full_comm);
		free(path_str);
		if (idx >= 0 && (!checks || (checks == 1 && !status) ||
			(checks == 2 && status)))
			exec_command(command, av + idx, prog_name, envp);
	}
}
/**
* sig_handler - Function to handle signals.
* @signum: Number passed by te signal function.
*/
void sig_handler(int signum)
{
	if (signum == SIGINT)
		write(STDOUT_FILENO, "\nCommand> ", 10);
}
/**
* main - Entry point for shell.
* @argc: Argument counter.
* @argv: Arguent vector.
* @envp: Environment for the program.
* Return: 0 on success.
*/
int main(int argc, char *argv[], char *envp[])
{
	char *command, *av[ARG_MAX], new_command[ARG_MAX], *alias[1000];
	short exit_signal = 0, getl_res, tok_res, i = 0, j = 0;

	alias[0] = NULL;
	signal(SIGINT, sig_handler);
	if (argc == 1)
	{
		while (1)
		{
			i = 0, j = 0, command = malloc(ARG_MAX);
			if (!command)
				return (-1);
			getl_res = get_input(argv[0], &command);
			if (getl_res == EOF)
				break;
			if (!_strcmp(command, "\n"))
				continue;
			while (command[i])
			{
				if (command[i] == '\n' && command[i + 1])
				{
					new_command[j++] = ' ', new_command[j++] = '\n';
					new_command[j++] = ' ', i++;
					continue;
				}
				new_command[j] = command[i], i++, j++;
			}
			free(command), new_command[j] = '\0';
			new_command[_strlen(new_command) - 1] = '\0';
			tok_res = tokenize(new_command, av, &exit_signal, alias);
			if (tok_res == 1)
				break;
			else if (tok_res == 2)
				continue;
			exec_command(new_command, av, argv[0], envp);
		}
	}
	if (exit_signal)
		my_exit(_strtok(NULL, " "), alias);
	free(command);
	return (0);
}
