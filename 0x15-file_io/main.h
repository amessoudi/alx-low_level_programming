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
int display_elf_header(const char *filename);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char e_class);
void print_data(unsigned char e_data);
void print_version(unsigned char e_version);
void print_osabi(unsigned char e_osabi);
void print_abiversion(unsigned char e_abiversion);
void print_type(uint16_t e_type);
void print_entry(uint64_t e_entry);

#endif /* MAIN_H */
