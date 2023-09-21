#include "monty.h"
#define BUFFER_SIZE 1024

/**
 * _getline - function that is used to read
 * a string or a line from an input stream.
 * @lineptr: pointer to a char
 * @n: a size_t variable
 * @stream: the file
 * Return: length of line or -1
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char buffer[BUFFER_SIZE];
	char *temp;
	size_t len;
	ssize_t bytes_read;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*lineptr = malloc(BUFFER_SIZE);
		if (*lineptr == NULL)
			return (-1);
		*n = BUFFER_SIZE;
	}

	bytes_read = fread(buffer, 1, BUFFER_SIZE, stream);
	if (bytes_read == 0)
		return (-1);

	len = strcspn(buffer, "\n");
	if (len == BUFFER_SIZE)
		len = bytes_read;

	if (len >= *n)
	{
        free(*lineptr);
        temp = malloc(len + 1);
		/*temp = realloc(*lineptr, len + 1);*/
		if (temp == NULL)
			return (-1);
		*lineptr = temp;
		*n = len + 1;
	}
	memcpy(*lineptr, buffer, len);
	(*lineptr)[len] = '\0';

	fseek(stream, len + 1 - bytes_read, SEEK_CUR);

	return (len);
}