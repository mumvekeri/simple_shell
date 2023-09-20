#include "shell.h"
/**
 * _split - Split a string into an array of substrings.
 * @str: The string to be split.
 * @sep: The separator used for splitting.
 * Return: An array of divided substrings.
 */
char **_split(char *str, char *sep)
{
	char *token, **substrings;
	int i = 0;

	token = strtok(str, sep);
	substrings = (char **)calloc(100, sizeof(char *));

	if (!substrings)
	{
		free(substrings);
		return (NULL);
	}
	while (token)
	{
		substrings[i] = token;
		token = strtok(NULL, sep);
		i++;
	}
	return (substrings);
}

