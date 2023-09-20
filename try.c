#include "shell.h"

/**
 * split_paths - Splits the `paths` string into an array of tokens.
 * @paths: The `paths` string.
 * Return: An array of tokens.
 */
char **split_paths(char *paths)
{
	char **path_tokens = NULL, *token = NULL, *temp = NULL;
	int idx = 0;

	temp = strtok(paths, "=");
	temp = strtok(NULL, "=");
	path_tokens = malloc(sizeof(char *) * 30);
	if (path_tokens == NULL)
	{
		free(paths);
		return (NULL);
	}
	token = strtok(temp, ":");
	while (token != NULL)
	{
		path_tokens[idx] = token;
		token = strtok(NULL, ":");
		idx++;
	}
	path_tokens[idx] = NULL; /*ARRAY OF ALL DIRECTORIES*/
	return (path_tokens);
}

/**
 * check_file_exists_and_is_executable - Checks if a
 * file exists and is executable.
 * @fullpath: The full path to the file.
 * Return: 1 if the file exists and is executable, 0 otherwise.
 */
int check_file_exists_and_is_executable(char *fullpath)
{
	if (access(fullpath, X_OK) == 0)
	{
		return (1);
	}
	return (0);
}

/**
 * get_full_path - returns a valid path else NULL
 * @paths: A string of multiple directories in the path
 * @cmd: Command string (Not an array)
 * Return: A Pointer to full string or NULL
 */
char *get_full_path(char *paths, char *cmd)
{
	char **path_tokens = NULL, *fullpath = NULL;
	int idx = 0;
	size_t len = 0;

	path_tokens = split_paths(paths);
	if (path_tokens == NULL)
	{
		free(paths);
		return (NULL);
	}
	while (path_tokens[idx] != NULL)
	{
		len = strlen(path_tokens[idx]) + strlen(cmd) + 2;
		fullpath = malloc(len);
		strcpy(fullpath, path_tokens[idx]);
		strcat(fullpath, "/");
		strcat(fullpath, cmd);

		if (check_file_exists_and_is_executable(fullpath))
		{
			free(path_tokens);
			free(paths);
			return (fullpath);
		}
		free(fullpath);
		fullpath = NULL;
		idx++;
	}
	free(path_tokens);
	free(paths);
	return (NULL);
}

