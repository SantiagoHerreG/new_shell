#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void _change_dir(char *path, char*command)
{
	int chdir_res = 0;
	char *old_dir, *new_dir, *home_ptr, *old_ptr;

	old_dir = malloc(100);
	new_dir = malloc(100);
	if (!old_dir || !new_dir)
	{
		free(command);
		free(old_dir);
		free(new_dir);
		exit(-1);
	}
	home_ptr = getenv("HOME");
	old_ptr = getenv("OLDPWD");
	getcwd(old_dir, 100);
	if (!path)
		chdir_res = chdir(home_ptr);
	else if (!_strcmp("-", path))
		chdir_res = chdir(old_ptr);
	else
		chdir_res = chdir(path);
	if (chdir_res)
	{
		perror("cd");
		free(old_dir);
		free(new_dir);
		return;
	}
	setenv("OLDPWD", old_dir, 1);
	getcwd(new_dir, 100);
	setenv("PWD", new_dir, 1);
	free(old_dir);
	free(new_dir);
}
