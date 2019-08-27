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
void my_exit(char *av[], char *alias[]);
int _atoi(char *);
short _getline(char **command, int *size, int fd);
void (*signal(int, void (*)(int)))(int);
void _change_dir(char *path);
short _strncmp(char *, char *, int);
short check_newlines(char *av[], short *idx);
char *getenvtok(char *envp[], char *var, char *token[]);
void set_var(char *arg1, char *arg2);
void unset_var(char *var_to_rm);
char *_strtok(char *base, char *delims);
short check_builtins(char *av[], char *alias[], char *filename);
int print_alias(char *av[], char *alias[]);
short set_alias(char *new_alias, char *alias[]);
int check_new_alias(char *new_alias);
void alias_expansion(char *av[], char *alias[]);
void expand_vars(char *av[]);
char *_num2str(int num);
void copy_array(char *av[], char *alias_exp[]);
short get_filename(char **filename, char *envp[]);
short create_write_file(const char *filename, char *content_to_wr);
void print_history(char *filename);
void print_number(int n);
void print_loop_his(char *, int *, int *);
extern int flag_hist;
extern int line_count;
#endif  /* HOLBERTON_H */
