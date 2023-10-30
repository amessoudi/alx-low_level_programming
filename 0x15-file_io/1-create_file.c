#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - creates a file with specified content
 * @filename: the name of the file to create
 * @text_content: the NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, status, length = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[length])
			length++;
		status = write(fd, text_content, length);
		if (status != length)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
