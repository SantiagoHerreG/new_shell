#include "holberton.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * create_write_file - function that creates and appends command history file
 * @filename: name of the file with the corresponding path to home
 * @content_to_wr: command of the user to be stored
 * Return: 1 on success
 */
short create_write_file(const char *filename, char *content_to_wr)
{
	int fd, len, write_chars;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0600);

	if (fd < 0)
		return (-1);

	if (content_to_wr && content_to_wr[0] != '\0')
	{
		for (len = 0; content_to_wr[len]; len++)
			;
		write_chars = write(fd, content_to_wr, len);
		close(fd);
		if (write_chars < 0 || write_chars != len)
			return (-1);
	}
	close(fd);
	return (1);
}

short get_filename(char **filename, char *envp[])
{
	char *token;
	short i = 0;
	while (_strncmp(envp[i], "HOME=", 5))
		i++;
	if (!envp[i])
		return (0);

	*filename = malloc(1024); /* ojo */
	if (!*filename)
		exit(-1);
	_strcpy(*filename, envp[i]);
	token = _strtok(*filename, "=");
	token = _strtok(NULL, ":");

	_strcpy(*filename, token);
	_strcat(*filename, "/");
	_strcat(*filename, "simple_shell_history");
	return (1);
}
void print_history(char *filename)
{
	int fd_h = 0, read_char = 1, close_res, i = 0, line_count = 0, flag = 0, j;
	char buffer[1000000];

	if (!filename)
		return;

	fd_h = open(filename, O_RDONLY);

	if (fd_h < 0)
		exit (-1);

	while (read_char > 0)
	{
		read_char = read(fd_h, buffer, 999999);
		if (read_char < 0)
			exit (-1);
		buffer[read_char] = '\0';
		if (read_char)
		{
			j = 0;
			while (buffer[j])
			{
				if (buffer[j] == '\n')
					line_count += 1;
				j++;
			}
			line_count %= 4096;
			while (buffer[i])
			{
				if (buffer[i] == '\n' && buffer[i + 1])
				{
					write(STDIN_FILENO, buffer + i, 1), i++;
					write(STDIN_FILENO, " ", 1);
					print_number(line_count), line_count++;
					write(STDIN_FILENO, "  ", 2);
				}
				else if (i == 0 && buffer[i + 1] && !flag)
				{			
					write(STDIN_FILENO, " ", 1);
					print_number(line_count), line_count++;
					write(STDIN_FILENO, "  ", 2);
					i++;
				}
				else
					write(STDIN_FILENO, buffer + i, 1), i++;
			}
			flag++;
		}
	}
	close_res = close(fd_h);

	if (close_res != 0)
		exit (-1);
}
