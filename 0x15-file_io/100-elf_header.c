#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * read_elf_header - Reads the ELF header from a file descriptor
 * @fd: File descriptor of the ELF file
 * @header: Pointer to Elf64_Ehdr structure to store header information
 *
 * Return: 1 on success, 0 on failure
 */
int read_elf_header(int fd, Elf64_Ehdr *header)
{
	if (read(fd, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		return (0);
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
		header->e_ident[EI_MAG1] != ELFMAG1 ||
		header->e_ident[EI_MAG2] != ELFMAG2 ||
		header->e_ident[EI_MAG3] != ELFMAG3)
		return (0);
	return (1);
}

/**
 * print_elf_header - Prints information from the ELF header
 * @header: Pointer to Elf64_Ehdr structure containing header information
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class:                             ELF%d\n",
		   header->e_ident[EI_CLASS] == ELFCLASS64 ? 64 : 32);
	printf("Data:                              2's complement, ");
	printf("%s\n",
		   header->e_ident[EI_DATA] == ELFDATA2LSB ? "little endian" : "big endian");
	printf("Version:                           %d (current)\n",
		   header->e_version);
	printf("OS/ABI:                            UNIX - System V\n");
	printf("ABI Version:                       %d\n",
		   header->e_ident[EI_ABIVERSION]);
	printf("Type:                              %d\n",
		   header->e_type);
	printf("Entry point address:               0x%lx\n",
		   (unsigned long)header->e_entry);
}

/**
 * main - Entry point, displays information from the ELF header
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr header;
	int fd;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (!read_elf_header(fd, &header))
	{
		close(fd);
		fprintf(stderr, "Error: Not an ELF file\n");
		exit(98);
	}

	print_elf_header(&header);

	close(fd);
	return (0);
}
