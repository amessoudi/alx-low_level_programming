#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to close.
 * @filename: The name of the file associated with the file descriptor.
 */
void close_file(int fd, char *filename)
{
	if (close(fd) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_content - Copies content from one file to another.
 * @fd_from: File descriptor for the source file.
 * @fd_to: File descriptor for the destination file.
 * @file_from: Name of the source file.
 * @file_to: Name of the destination file.
 */
void copy_content(int fd_from, int fd_to, char *file_from, char *file_to)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written, total_written;

	while (1)
	{
		bytes_read = read(fd_from, buffer, 1024);
		if (bytes_read > 0)
		{
			total_written = 0;
			do {
				bytes_written = write(fd_to, buffer + total_written, bytes_read - total_written);
				if (bytes_written < 0)
				{
					dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
					exit(99);
				}
				total_written += bytes_written;
			} while (bytes_read > total_written);
		}
		else if (bytes_read < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
			exit(98);
		}
		else
		{
			break;
		}
	}
}

/**
 * main - Entry point, copies content from one file to another.
 * @argc: The number of command line arguments.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success, or exits with a status code on error.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to < 0)
	{
		close_file(fd_from, argv[1]);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	copy_content(fd_from, fd_to, argv[1], argv[2]);

	close_file(fd_from, argv[1]);
	close_file(fd_to, argv[2]);

	return (0);
}
