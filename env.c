#include "shell.h"
/**
 * HandleEnvironmentError - displays excess environment arguments error
 * @toks: - an array of tokens
 */
void HandleEnvironmentError(char **toks)
{
	char error[300] = "";

	_strcpy(error, "env: '");
	_strcat(error, toks[1]);
	_strcat(error, "': No such file or directory");
	write(STDOUT_FILENO, error, _strlen(error));
	write(STDOUT_FILENO, "\n", 1);
}
/**
 * print_env - prints environment variables.
 * @tokens: tokenized input.
 * Return: 1 (Success).
 */
int print_env(char **tokens)
{
	int i = 0;

	if (tokens[1] != NULL)
	{
		HandleEnvironmentError(tokens);
		return (1);
	}
	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

