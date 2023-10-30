#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <elf.h>

void print_elf_header(Elf64_Ehdr *header);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char e_ident);
void print_data(unsigned char e_ident);
void print_version(unsigned char e_ident);
void print_osabi(unsigned char e_ident);
void print_abiversion(unsigned char e_ident);
void print_type(uint16_t e_type);
void print_entry(uint64_t e_entry);

int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		return 98;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return 98;
	}

	if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		fprintf(stderr, "Error: Not an ELF file or read failed\n");
		close(fd);
		return 98;
	}

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		return 98;
	}

	print_elf_header(&header);
	close(fd);
	return 0;
}

void print_elf_header(Elf64_Ehdr *header)
{
	printf("Magic:   ");
	print_magic(header->e_ident);
	print_class(header->e_ident[EI_CLASS]);
	print_data(header->e_ident[EI_DATA]);
	print_version(header->e_ident[EI_VERSION]);
	print_osabi(header->e_ident[EI_OSABI]);
	print_abiversion(header->e_ident[EI_ABIVERSION]);
	print_type(header->e_type);
	print_entry(header->e_entry);
}

void print_magic(unsigned char *e_ident)
{
	int i;
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%.2x ", e_ident[i]);
	}
	printf("\n");
}

void print_class(unsigned char e_ident)
{
	printf("Class:                             ");
	switch (e_ident)
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident);
	}
}

void print_data(unsigned char e_ident)
{
	printf("Data:                              ");
	switch (e_ident)
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Invalid data encoding\n");
	}
}

void print_version(unsigned char e_ident)
{
	printf("Version:                           %d", e_ident);
	if (e_ident == EV_CURRENT)
	{
		printf(" (current)\n");
	}
	else
	{
		printf("\n");
	}
}

void print_osabi(unsigned char e_ident)
{
	(void)e_ident;  /* To avoid unused parameter warning */
	printf("OS/ABI:                            UNIX - System V\n");
}

void print_abiversion(unsigned char e_ident)
{
	printf("ABI Version:                       %d\n", e_ident);
}

void print_type(uint16_t e_type)
{
	printf("Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (No file type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		if (e_type >= ET_LOOS && e_type <= ET_HIOS)
		{
			printf("OS-specific\n");
		}
		else if (e_type >= ET_LOPROC) /* Adjusted this line */
		{
			printf("Processor-specific\n");
		}
		else
		{
			printf("<unknown: %x>\n", e_type);
		}
	}
}

void print_entry(uint64_t e_entry)
{
	printf("Entry point address:               0x%lx\n", e_entry);
}
