#include "holberton.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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
