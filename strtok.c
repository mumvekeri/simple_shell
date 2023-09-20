#include "shell.h"
/**
 * isDelimiter - Checks if the character 'c' is a delimiter.
 * @c: The character to check.
 * @delimiters: A string containing delimiter characters.
 * Return: 1 if 'c' is a delimiter, 0 otherwise.
 */
int isDelimiter(char *c, const char *delimiters)
{
	int i = 0;

	if (c == NULL || delimiters == NULL)
		return (0);

	while (delimiters[i] != '\0')
	{
		if (*c == delimiters[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * customStrtok - Tokenizes the input string.
 * @str: The string to be tokenized.
 * @delimiters: The delimiter characters.
 * Return: A pointer to the next token or NULL if there are no more tokens.
 */
char *customStrtok(char *str, const char *delimiters)
{
	static char *remaining;
	char *delimiterPtr, *token;

	if (str != NULL)
		remaining = str;

	if (remaining == NULL || *remaining == '\0')
		return (NULL);

	delimiterPtr = strpbrk(remaining, delimiters);

	if (delimiterPtr != NULL)
	{
		*delimiterPtr = '\0';
		delimiterPtr++;

		while (isDelimiter(delimiterPtr, delimiters))
		{
			*delimiterPtr = '\0';
			delimiterPtr++;
		}
	}

	token = remaining;
	remaining = delimiterPtr;

	if (*token == '\0')
		return (NULL);

	return (token);
}

