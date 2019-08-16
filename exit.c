#include "holberton.h"
#include <stdlib.h>
/**
 * my_exit - function that exits the program with specified state
 * @exit_status: pointer to the argument of exit
 * @command: double pointer to memory allocated for command line
 * Return: void
 */

void my_exit(char* exit_status, char ** command)
{
        int i;

        if(exit_status)
        {
                i = atoi(exit_status);
                free(*command);
                exit(i);
        }
        else
        {
	        free(*command);
        	exit(0);
        }
}
