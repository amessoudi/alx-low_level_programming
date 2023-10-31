#include "main.h"

/**
 * print_magic - Prints the magic numbers of the ELF header
 * @e_ident: The ELF identification array
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * print_class - Prints the class of the ELF file
 * @e_ident: The ELF class
 */
void print_class(unsigned char e_ident)
{
	printf("  Class:                             ");
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

/**
 * print_data - Prints the data encoding of the ELF file
 * @e_ident: The ELF data encoding
 */
void print_data(unsigned char e_ident)
{
	printf("  Data:                              ");
	switch (e_ident)
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident);
	}
}

/**
 * print_version - Prints the version of the ELF header
 * @e_ident: The ELF version
 */
void print_version(unsigned char e_ident)
{
	printf("  Version:                           ");
	if (e_ident == EV_CURRENT)
		printf("1 (current)\n");
	else
		printf("<unknown: %x>\n", e_ident);
}

/**
 * print_osabi - Prints the OS/ABI identification of the ELF file
 * @e_ident: The ELF OS/ABI identification
 */
void print_osabi(unsigned char e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident)
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_AIX:
		printf("UNIX - AIX\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_MODESTO:
		printf("Novell - Modesto\n");
		break;
	case ELFOSABI_OPENBSD:
		printf("UNIX - OpenBSD\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident);
	}
}

/**
 * print_abiversion - Prints the ABI version of the ELF file
 * @e_ident: The ELF ABI version
 */
void print_abiversion(unsigned char e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident);
}

/**
 * print_type - Prints the type of the ELF file
 * @e_type: The ELF type
 */
void print_type(uint16_t e_type)
{
	printf("  Type:                              ");
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
		printf("\n");
	}
}

/**
 * print_entry - Prints the entry point address of the ELF file
 * @e_entry: The ELF entry point address
 */
void print_entry(uint64_t e_entry)
{
	printf("  Entry point address:               0x%lx\n", e_entry);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	unsigned char e_ident[EI_NIDENT];
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return 98;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return 98;
	}

	if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
	{
		fprintf(stderr, "Error reading ELF header\n");
		close(fd);
		return 98;
	}

	if (memcmp(e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Not an ELF file\n");
		close(fd);
		return 98;
	}

	if (lseek(fd, 0, SEEK_SET) == (off_t)-1)
	{
		perror("Error seeking in file");
		close(fd);
		return 98;
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		fprintf(stderr, "Error reading ELF header\n");
		close(fd);
		return 98;
	}

	close(fd);

	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident[EI_CLASS]);
	print_data(header.e_ident[EI_DATA]);
	print_version(header.e_ident[EI_VERSION]);
	print_osabi(header.e_ident[EI_OSABI]);
	print_abiversion(header.e_ident[EI_ABIVERSION]);
	print_type(header.e_type);
	print_entry(header.e_entry);

	close(fd);
	return (0);
}
