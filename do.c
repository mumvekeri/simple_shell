#include "shell.h"
/**
 * custom_exit - Exits the shell with a specified exit status.
 * @toks: An array of tokens containing the exit status.
 * Return: 0 (Success)
 */
int custom_exit(char **toks)
{
	int exit_status;

	if (toks[1] != NULL)
	{
		exit_status = atoi(toks[1]);
		if (exit_status > 0)
			exit(exit_status);
		else if (exit_status == 0 && _strcmp(toks[1], "0") == 0)
			return (0);
		else if (exit_status == 0 && _strcmp(toks[1], "0") != 0)
		{
			return (0);
		}
	}
	return (0);
}
