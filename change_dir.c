#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <linux/limits.h>
/**
* _change_dir - Function to handle the cd builtin.
* @path: Path to go.
*/
void _change_dir(char *path)
{
	int chdir_res = 0, i = 0, j = 0;
	char ptr_dir[ARG_MAX], home_ptr[ARG_MAX], old_ptr[ARG_MAX];

	while (environ[i] && (_strncmp(environ[i], "HOME=", 5)))
		i++;

	while (environ[j] && (_strncmp(environ[j], "OLDPWD=", 7)))
		j++;

	_strcpy(old_ptr, environ[j] + 7);
	_strcpy(home_ptr, environ[i] + 5);
	getcwd(ptr_dir, ARG_MAX);
	if (!path)
		chdir_res = chdir(home_ptr);
	else if (!_strcmp("-", path))
		chdir_res = chdir(old_ptr);
	else
		chdir_res = chdir(path);
	if (chdir_res)
	{
		perror("cd");
		return;
	}
	set_var("OLDPWD", ptr_dir);
	getcwd(ptr_dir, ARG_MAX);
	set_var("PWD", ptr_dir);
}
