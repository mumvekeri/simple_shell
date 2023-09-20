#include "shell.h"

/**
 * tokenize - Splits a string into tokens based on delimiters.
 * @input: The input string to be tokenized.
 * Return: An array of pointers to the tokens.
 */

char **tokenize(char *input)
{
	char **tokens = NULL;
	int index = 0;
	char *token = NULL;
	char *delimiter = " \n";

	tokens = malloc(sizeof(char *) * 25);

	if (tokens == NULL)
		return (NULL);

	token = strtok(input, delimiter);

	while (token != NULL)
	{
		tokens[index] = token;
		token = strtok(NULL, delimiter);
		index++;
	}
	tokens[index] = NULL;
	return (tokens);
}

