#include "shell.h"

/**
 * _strncmp - Compares two strings up to n bytes.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of bytes to be compared.
 * Return: 0 if strings match up to n bytes, 1 otherwise.
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t a;

	if (!s1 || !s2)
	return (1);

	for (a = 0; a < n; a++)
	{
		if (s1[a] != s2[a])
		return (1);
	}
	return (0);
}
/**
 * _strcmp - compares two strings
 * @str1: the first string.
 * @str2: the second string.
 * Return: 0 if the strings are equal, a positive value if str1 is greater,
 * and a negative value if str2 is greater.
 */
int _strcmp(const char *str1, const char *str2)
{
	size_t i;

	if (str1 == NULL && str2 == NULL)
		return (0);
	if (str1 == NULL)
		return (-1);
	if (str2 == NULL)
		return (1);
	for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
	{
		if (str1[i] == '\0' && str2[i] != '\0')
			return (-1);
		if (str1[i] != '\0' && str2[i] == '\0')
			return (1);
		if (str1[i] > str2[i])
			return (1);
		if (str1[i] < str2[i])
			return (-1);
	}
	return (0);
}
/**
 * _strdup - Creates a duplicate of the given string.
 * @str: String to be duplicated.
 * Return: Pointer to the duplicated string or NULL if memory allocation fails.
 */
char *_strdup(char *str)
{
	int a, len;
	char *duplicate;

	len = strlen(str);
	duplicate = malloc(sizeof(char) * (len + 1));
	/* +1 for the null terminator*/

	if (!duplicate)
	return (NULL);

	for (a = 0; str[a]; a++)
	duplicate[a] = str[a];
	duplicate[a] = '\0';

	return (duplicate);
}

