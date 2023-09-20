#include "shell.h"
/**
 * _getenv - Get the value of an environment variable.
 * @env_variable: The name of the environment variable to retrieve.
 * Return: A pointer to the value of the specified environment variable.
 */
char *_getenv(char *env_variable)
{
	int i = 0, a;
	int found = 0;

	while (environ[i])
	{
		found = 1;

		for (a = 0; environ[i][a] != '='; a++)
		{
			if (environ[i][a] != env_variable[a])
				found = 0;
		}

		if (found == 1)
			break;

		i++;
	}

	return (&environ[i][a + 1]);
}

/**
 * _env - Print the environment variables.
 */
void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

