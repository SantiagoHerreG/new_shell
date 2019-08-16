#include "holberton.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <sys/wait.h>
int main(int argc, __attribute__((unused)) char *argv[])
{
	char *command = malloc(100), *av[5], tok[100], *av2;
	size_t size = 100;
	pid_t child;
	int status, i = 0;

	if (argc == 1)
	{
		for (i = 0; i < 5; i++)
			av[i]=malloc(20);
		while (1)
		{
			i = 0;
			_strcpy(tok,"/bin/");
			write(1, "My_Prompt> ", 11);
			getline(&command, &size, stdin);
			command[_strlen(command)-1]='\0';
			av2=strtok(command, " ");
			_strcpy(av[i++],av2);
			if (!_strcmp("exit",av[0]))
				break;
			while((av2=strtok(NULL," ")))
				_strcpy(av[i++],av2);
			while(i<5)
			{
				free(av[i]);
				av[i++]=NULL;
			}
			av[i]=NULL;
			_strcat(tok, av[0]);
			_strcpy(av[0], tok);
			child = fork();
			if (!child)
			{
				execve(av[0], av, NULL);
				exit(0);
			}
			else
				wait(&status);
		}
	}
	free(command);
	for (i=0;i<5;i++)
	{
		if (av[i])
			free(av[i]);
	}
	return (0);
}
