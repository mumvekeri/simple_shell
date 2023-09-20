#include "shell.h"
/**
 * _memchr - Finds a character in a string.
 * @str: The string to search.
 * @c: The character to find.
 * @count: The number of characters to search.
 * Return: A pointer to the character if found, or NULL if not found.
 */
void *_memchr(char *str, char c, ssize_t count)
{
	ssize_t index;

	if (!str)
		return (NULL);

	for (index = 0; index < count; index++)
	{
		if (str[index] == c)
			return (str + index);
	}
	return (NULL);
}

/**
 * _getline - Reads a line from a file descriptor.
 * @lineBuffer: A pointer to the variable to store the input stream.
 * @bufferSize: The size of the pre-allocated memory.
 * @fileDescriptor: The input source file descriptor.
 * Return: The number of characters read, or -1 on error.
 */
ssize_t _getline(char **lineBuffer, size_t *bufferSize, int fileDescriptor)
{

	size_t length;
	char readBuffer[MAX_LINE] = "";
	ssize_t bytesRead, totalBytesRead = 0;

	if (lineBuffer == NULL || bufferSize == NULL)
		return (-1);

	while (1)
	{
		bytesRead = read(fileDescriptor, readBuffer + totalBytesRead,
				MAX_LINE - totalBytesRead);

		if ((bytesRead == -1) || (bytesRead == 0 && totalBytesRead == 0))
			return (-1);

		totalBytesRead += bytesRead;

		if (bytesRead == 0 || (_memchr(readBuffer, '\n',
						totalBytesRead) != NULL))
			break;
	}

	readBuffer[totalBytesRead] = '\0';
	length = strlen(readBuffer);

	*lineBuffer = malloc(length + 1);
	memcpy(*lineBuffer, readBuffer, length + 1);
	*bufferSize = length;

	return ((ssize_t)length);
}

