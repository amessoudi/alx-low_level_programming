#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the file to read
 * @letters: the number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print,
 * 0 if the file cannot be opened or read, if filename is NULL,
 * or if write fails or does not write the expected amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nread, nwritten, nw;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	nread = read(fd, buffer, letters);
	if (nread == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	for (nwritten = 0; nwritten < nread; nwritten += nw)
	{
		nw = _putchar(buffer[nwritten]);
		if (nw == -1)
		{
			free(buffer);
			close(fd);
			return (0);
		}
	}

	free(buffer);
	close(fd);
	return (nwritten);
}
