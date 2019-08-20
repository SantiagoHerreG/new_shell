#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <signal.h>

extern char **environ;
char *_strcpy(char *, char *);
int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat(char *dest, char *src);
void my_exit(char *exit_status);
int _atoi(char *);
short _getline(char **command, int *size, int fd);
void (*signal(int, void (*)(int)))(int);
void _change_dir(char *path);
short _strncmp(char *, char *, int);
void check_newlines(char *av[], short *idx);
char *getenvtok(char *envp[], char *var, char *token[]);
void set_unset_var(char *arg1, char *arg2);

#endif /* HOLBERTON_H */
