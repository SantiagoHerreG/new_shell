/**
* _strncmp - Compares n bytes of a string.
* @s1: First string.
* @s2: Second string.
* @n: Number of bytes to be compared.
* Return: 0 if equal, difference otherwise.
*/
short _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n && *(s1 + i) && *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	if (i < n && *(s1 + i) != *(s2 + i))
		return (*(s1 + i) - *(s2 + i));
	return (0);
}
