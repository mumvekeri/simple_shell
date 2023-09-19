#include "shell.h"

/**
 * _strlen - computes the length of a string
 * @str: the string
 * Return: the length of the string
 */
size_t _strlen(const char *str)
{
	size_t i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination string.
 * @src: the source string to append.
 * Return: a pointer to the concatenated string.
 */
char *_strcat(char *dest, const char *src)
{
	size_t i = 0, a = 0;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (a = 0; src[a] != '\0'; a++)
		dest[i++] = src[a];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - copies a string into a buffer.
 * @dest: the destination buffer.
 * @src: the source buffer to copy from.
 * Return: a pointer to the destination buffer with copied contents.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	if (src == NULL || dest == NULL)
		return (NULL);
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

