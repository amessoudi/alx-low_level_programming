#include "main.h"

/**
 * close_fd - Closes a file descriptor and checks for errors
 * @fd: File descriptor to close
 * @filename: Name of the file associated with the file descriptor
 */
void close_fd(int fd, const char *filename)
{
	if (close(fd) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d for file %s\n",
				fd, filename);
		exit(100);
	}
}

/**
 * copy_content - Copies content from one file to another
 * @fd_from: File descriptor to copy from
 * @fd_to: File descriptor to copy to
 * @file_from: Name of the source file
 * @file_to: Name of the destination file
 */
void copy_content(int fd_from, int fd_to, const char *file_from,
				  const char *file_to)
{
	char buffer[BUF_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close_fd(fd_from, file_from);
			close_fd(fd_to, file_to);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}

	if (bytes_read < 0)
	{
		close_fd(fd_from, file_from);
		close_fd(fd_to, file_to);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
 * main - Entry point, copies the content of a file to another file
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success
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
		close_fd(fd_from, argv[1]);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	copy_content(fd_from, fd_to, argv[1], argv[2]);

	close_fd(fd_from, argv[1]);
	close_fd(fd_to, argv[2]);

	return (0);
}
