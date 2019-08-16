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
	char *copy_dest, *copy_src;

	copy_src= src;
	copy_dest = dest;
	while ((*dest = *copy_src) != '\0')
	{
	dest++;
	copy_src++;
	if (*copy_src == '\0')
	*dest = *copy_src;
	}
return (copy_dest);
}
