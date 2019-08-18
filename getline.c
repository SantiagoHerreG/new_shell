#include "holberton.h"
#include <stdio.h>
#include <unistd.h>

/**
 * _getline - function that reads input from stdin
 * @command: address of pointer to buffer
 * @size: count of chars to be read as a line
 * @fd: file descriptor for rread function
 * Return: count of chars read including newline/ excluding terminating null
 */

short _getline(char **command, size_t *size, int fd)
{
	short read_bytes = 0, new_read = 0;
	size_t i = 0;

	read_bytes = read(fd, *command, 1);

	if (read_bytes == 0)
		return (-1);
	else if (read_bytes == -1)
	{
		free(*command);
		perror("Could not read input");
		exit(-1);
	}
	i++;

	while (*command[0] != '\n' && i < *size)
	{
		new_read = read(fd, ++(*command), 1);
		if (new_read == 0)
			return (-1);
		else if (new_read == -1)
		{
			free(*command);
			perror("Could not read input");
			exit(-1);
		}
		read_bytes += new_read;
		i++;
	}
	*(++(*command)) = '\0';

	return (read_bytes);
}
