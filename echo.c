#include "shell.h"
/**
 * displayEnvironmentVariables - Display Environment Variables
 * @cmd: Parsed Command
 * @lastExitStatus: Status of the last command executed (unused)
 * Return: 0 (always)
 */
int displayEnvironmentVariables(char **cmd, int lastExitStatus)
{
	size_t i;
	int len;

	(void)cmd;
	(void)lastExitStatus;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * displayHelp - Display Help For Built-ins
 * @cmd: Parsed Command
 * @lastExitStatus: Status of the last command executed (unused)
 * Return: 0 on success, -1 on failure
 */
int displayHelp(char **cmd, int lastExitStatus)
{
	int fileDescriptor, fileWrite, fileRead = 1;
	char character;

	(void)lastExitStatus;

	fileDescriptor = open(cmd[1], O_RDONLY);
	if (fileDescriptor < 0)
	{
		perror("Error");
		return (0);
	}
	while (fileRead > 0)
	{
		fileRead = read(fileDescriptor, &character, 1);
		fileWrite = write(STDOUT_FILENO, &character, fileRead);
		if (fileWrite < 0)
		{
			return (-1);
		}
	}
	print_char('\n');
	return (0);
}
