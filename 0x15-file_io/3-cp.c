#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

void close_fd(int fd, const char *filename);
int open_file(char *file, int flags, mode_t mode);
void copy_content(int fd_from, int fd_to, char *file_from, char *file_to);

/**
 * close_fd - Closes a file descriptor and checks for errors
 * @fd: File descriptor to close
 * @filename: Name of the file associated with the file descriptor
 *
 * Description: If closing the file descriptor fails, the function
 *              prints an error message to stderr and exits with code 100
 */
void close_fd(int fd, const char *filename)
{
	if (close(fd) < 0)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d for file %s\n", fd, filename);
		exit(100);
	}
}

/**
 * open_file - Opens a file and checks for errors
 * @file: Name of the file to open
 * @flags: Flags for opening the file
 * @mode: Mode for file creation
 * Return: File descriptor on success, exits on failure
 */
int open_file(char *file, int flags, mode_t mode)
{
	int fd = open(file, flags, mode);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't %s %s\n",
			(flags & O_RDONLY) ? "read from file" : "write to", file);
		exit((flags & O_RDONLY) ? 98 : 99);
	}
	return (fd);
}

/**
 * copy_content - Copies content from one file to another
 * @fd_from: File descriptor of source file
 * @fd_to: File descriptor of destination file
 * @file_from: Name of source file
 * @file_to: Name of destination file
 */
void copy_content(int fd_from, int fd_to, char *file_from, char *file_to)
{
	ssize_t bytes_read, bytes_written;
	char buffer[BUF_SIZE];

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
 * main - Copies the content of a file to another file
 * @argc: Argument count
 * @argv: Argument vector
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

	fd_from = open_file(argv[1], O_RDONLY, 0);
	fd_to = open_file(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	copy_content(fd_from, fd_to, argv[1], argv[2]);

	close_fd(fd_from, argv[1]);
	close_fd(fd_to, argv[2]);

	return (0);
}
