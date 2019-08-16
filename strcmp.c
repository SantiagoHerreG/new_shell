#include "holberton.h"
#include <stdio.h>
/**
 * _strcmp - compares the ascii sum of characters in two strings
 * @dest: pointer
 * @src: pointer
 * Return: integer. positive if the first string is bigger
 */
int _strcmp(char *dest, char *src)
{
	int i = 0, k = 0;

	while (dest[i] != '\0')
	{
		if (dest[i] > src[i])
		{
			k = dest[i] - src[i];
			break;
		}
		else if (dest[i] < src[i])
		{
			k = dest[i] - src[i];
			break;
		}
	i++;
	}
	if (src[i] != '\0' && k == 0)
	k = -src[i];
	return (k);
}
