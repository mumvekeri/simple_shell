#include "shell.h"

/**
 * handle_builtins - Handles shell built-in commands.
 * @args: An array of command arguments.
 * @progname: The name of the program (unused in this function).
 * @buffer: The buffer containing the user's input.
 *
 * Return: 1 if a built-in command is executed, 0 otherwise.
 */
int handle_builtins(char **args, char *progname, char *buffer)
{
	int executed = 0;

	(void)progname;
	(void)buffer;

	if (strcmp(args[0], "exit") == 0)
	{
		custom_exit(args);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		PrintEnvironment(args);
		executed = 1;
	}
	return (executed);
}

