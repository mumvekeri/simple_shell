#include "shell.h"
/**
 * SetEnvironment - sets environment variables.
 * @tokens: tokenized input.
 * Return: Always 1 (Success).
 */
int SetEnvironment(char **tokens)
{
	int i = 0;
	char newEnvironment[MAX_LINE], *newEnvironmentPtr;

	if (tokens[1] == NULL)
	{
		print_env(tokens);
		return (1);
	}
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], tokens[1], strlen(tokens[1])) == 0)
		{
			free(environ[i]);
			strcpy(environ[i], tokens[1]);
			strcat(environ[i], "=");
			strcat(environ[i], tokens[2]);
			return (1);
		}
		i++;
	}
	strcpy(newEnvironment, tokens[1]);
	strcat(newEnvironment, "=");
	if (tokens[2] != NULL)
		strcat(newEnvironment, tokens[2]);
	newEnvironmentPtr = malloc(_strlen(newEnvironment) + 1);
	if (newEnvironmentPtr == NULL)
	{
		write(STDERR_FILENO, "Could not set", 16);
		return (1);
	}
	strcpy(newEnvironmentPtr, newEnvironment);
	environ[i] = newEnvironmentPtr;
	environ[i + 1] = NULL;
	return (1);
}

/**
 * UpdateExistingEnvironment - updates an existing environment variable.
 * @update: the new value.
 * @tokens: tokenized command.
 * Return: 1 (if it exists).
 */
int UpdateExistingEnvironment(char *update, char **tokens)
{
	char **env;

	env = environ;
	while (*env != NULL)
	{
		if (strncmp(*env, tokens[1], strlen(tokens[1])) == 0 &&
			(*env)[_strlen(tokens[1])] == '=')
		{
			*env = update;
			return (1);
		}
		env++;
	}
	return (0);
}

/**
 * UnsetEnvironment - unsets an environment variable.
 * @tokens: tokenized input.
 * Return: update_environment.
 */
int UnsetEnvironment(char **tokens)
{
	int i = 0, k = 0;

	if (tokens[1] == NULL)
	{
		write(STDERR_FILENO, "Couldn't set", 12);
		return (1);
	}
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], tokens[1], strlen(tokens[1])) == 0)
			break;
		i++;
	}
	if (environ[i] == NULL)
	{
		write(STDERR_FILENO, "Could not set", 16);
		return (1);
	}
	while (environ[k] != NULL)
		k++;
	k--;
	environ[i] = environ[k];
	environ[k] = NULL;
	return (1);
}

/**
 * ExecuteBuiltins - checks and executes built-in commands.
 * @tokens: tokenized string.
 * Return: 1
 */
int ExecuteBuiltins(char **tokens)
{
	int i;
	char *builtinStrings[] = {"setenv", "env", "exit", "unsetenv"};
	typedef int (*BuiltinFunction)(char **);
	BuiltinFunction builtinFunctions[5] = {SetEnvironment,
		print_env,
		custom_exit,
		UnsetEnvironment};

	for (i = 0; i < 4; i++)
	{
		if (strcmp(builtinStrings[i], tokens[0]) == 0)
			return ((*builtinFunctions[i])(tokens));
	}
	return (-1);
}

