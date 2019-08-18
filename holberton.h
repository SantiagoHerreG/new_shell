#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#define _POSIX_C_SOURCE 200809L
#include <signal.h>
char *_strcpy(char *, char *);
int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat(char *dest, char *src);
void my_exit(char* exit_status, char ** command);
int _atoi(char *);
void (*signal(int, void (*)(int)))(int);


#endif /* HOLBERTON_H */
