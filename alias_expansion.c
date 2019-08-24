#include "holberton.h"


int alias_expansion(char *av[], char *alias[], char *arguments)
{
       int i = 0;
       char al_name[ARG_MAX], *token;
       while (alias[i])
       {
               _strcpy(al_name, alias[i]);
               _strtok(al_name, "=");
               eq_len = _strlen(al_name);
               if (!_strcmp(al_name, av[0]) && alias[i][eq_len] == '=')
                       break;
               i++;
       }
       if (!alias[i])
               return (0);
       token = _strtok(NULL, "=");
       j = 1, i = 0;
       if (token[j] != '\'')
               av[0][i++] = token[j++];
       while (token[j + 1])
       {
               if (token[j] != '\'')
                       av[0][i++] = token[j++];
       }
       av[0][i] = '\0';
       return (1);
}
