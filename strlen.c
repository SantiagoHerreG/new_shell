#include "holberton.h"
/**
 * _strlen - returns the length of a string
 * @s: pointer to a string
 * Return: number of chars in the string
 */
int _strlen(char *s)
{
	int n = 0;

	if (s)
		for (n = 0; *s; s++)
			n++;
	return (n);
}
