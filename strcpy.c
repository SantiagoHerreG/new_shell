#include "holberton.h"
#include <stdio.h>
/**
 * _strcpy - copies a string
 * @dest: pointer to the address of the copy
 * @src: pointer to an array of char
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	if (dest && src)
		while ((*dest++ = *src++))
			;
	return (dest);
}
