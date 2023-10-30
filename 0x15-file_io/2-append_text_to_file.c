#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: the name of the file.
 * @text_content: the NULL terminated string to add at the end of the file.
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t w_len;
	size_t len = 0;

	if (!filename)
		return (-1);

	if (!text_content)
		return (1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	while (text_content[len])
		len++;

	w_len = write(fd, text_content, len);
	close(fd);

	if (w_len != len)
		return (-1);

	return (1);
}
