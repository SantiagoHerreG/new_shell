#include "holberton.h"
/**
 * _strcat - concatenates two strings into the first one
 * @dest:  pointer to the first string
 * @src: pointer to the second string
 * Return: pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int n, i = 0;

	char *new;

	for (n = 0; dest[n] != '\0'; n++)
		;
		while (src[i] != '\0')
		{
			dest[n++] = src[i++];
		}
	if (src[i] == '\0')
		dest[n] = src[i];

	new = dest;
	return (new);
}
