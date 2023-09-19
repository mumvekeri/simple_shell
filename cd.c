#include "shell.h"

/**
 * handleChangeDirectory - Handle the "cd" built-in command
 * @cmd: Parsed Command
 * @lastExitStatus: Status of the last command executed (unused)
 * Return: 0 on success, -1 on failure
 */
int handleChangeDirectory(char **cmd, int lastExitStatus)
{
	int changeDirStatus = -1;
	char currentWorkingDir[PATH_MAX];

	(void)lastExitStatus;

	if (cmd[1] == NULL)
	{
		changeDirStatus = chdir(getenv("HOME"));
	}
	else if (_strcmp(cmd[1], "-") == 0)
	{
		changeDirStatus = chdir(getenv("OLDPWD"));
	}
	else
	{
		changeDirStatus = chdir(cmd[1]);
	}
	if (changeDirStatus == -1)
	{
		perror("hsh error");
		return (-1);
	}
	else if (changeDirStatus != -1)
	{
		getcwd(currentWorkingDir, sizeof(currentWorkingDir));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", currentWorkingDir, 1);
	}
	return (0);
}
