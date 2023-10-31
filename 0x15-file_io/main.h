#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <elf.h>

#define BUF_SIZE 1024

void close_fd(int fd, const char *filename);
void copy_content(int fd_from, int fd_to, const char *file_from,
				  const char *file_to);
ssize_t read_textfile(const char *filename, size_t letters);
int append_text_to_file(const char *filename, char *text_content);
void close_fd(int fd, const char *filename);


#endif /* MAIN_H */
