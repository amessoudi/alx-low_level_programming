#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <elf.h>

void print_magic(unsigned char *e_ident) {
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

void print_class(unsigned char ei_class) {
	printf("  Class:                             ");
	switch (ei_class) {
		case ELFCLASS32: printf("ELF32\n"); break;
		case ELFCLASS64: printf("ELF64\n"); break;
		default:         printf("<unknown: %x>\n", ei_class);
	}
}

void print_data(unsigned char ei_data) {
	printf("  Data:                              ");
	switch (ei_data) {
		case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
		case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
		default:          printf("<unknown: %x>\n", ei_data);
	}
}

void print_version(unsigned char ei_version) {
	printf("  Version:                           ");
	if (ei_version == EV_CURRENT)
		printf("1 (current)\n");
	else
		printf("<unknown: %x>\n", ei_version);
}

void print_osabi(unsigned char ei_osabi) {
	printf("  OS/ABI:                            ");
	switch (ei_osabi) {
		case ELFOSABI_NONE:       printf("UNIX - System V\n"); break;
		case ELFOSABI_HPUX:       printf("UNIX - HP-UX\n"); break;
		case ELFOSABI_NETBSD:     printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_LINUX:      printf("UNIX - Linux\n"); break;
		case ELFOSABI_SOLARIS:    printf("UNIX - Solaris\n"); break;
		case ELFOSABI_AIX:        printf("UNIX - AIX\n"); break;
		case ELFOSABI_IRIX:       printf("UNIX - IRIX\n"); break;
		case ELFOSABI_FREEBSD:    printf("UNIX - FreeBSD\n"); break;
		case ELFOSABI_TRU64:      printf("UNIX - TRU64\n"); break;
		case ELFOSABI_MODESTO:    printf("Novell - Modesto\n"); break;
		case ELFOSABI_OPENBSD:    printf("UNIX - OpenBSD\n"); break;
		default:                  printf("<unknown: %x>\n", ei_osabi);
	}
}

void print_abiversion(unsigned char ei_abiversion) {
	printf("  ABI Version:                       %u\n", ei_abiversion);
}

void print_type(uint16_t e_type, unsigned char ei_data) {
	printf("  Type:                              ");
	switch (e_type) {
		case ET_NONE:   printf("NONE (None)\n"); break;
		case ET_REL:    printf("REL (Relocatable file)\n"); break;
		case ET_EXEC:   printf("EXEC (Executable file)\n"); break;
		case ET_DYN:    printf("DYN (Shared object file)\n"); break;
		case ET_CORE:   printf("CORE (Core file)\n"); break;
		default:        printf("<unknown: %x>\n", e_type);
	}
}

void print_entry(uint64_t e_entry, unsigned char ei_class) {
	printf("  Entry point address:               ");
	if (ei_class == ELFCLASS32)
		printf("0x%x\n", (uint32_t)e_entry);
	else
		printf("0x%lx\n", e_entry);
}

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return 98;
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror("open");
		return 98;
	}

	unsigned char e_ident[EI_NIDENT];
	if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT) {
		perror("read");
		close(fd);
		return 98;
	}

	if (memcmp(e_ident, ELFMAG, SELFMAG) != 0) {
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		return 98;
	}

	if (lseek(fd, 0, SEEK_SET) != 0) {
		perror("lseek");
		close(fd);
		return 98;
	}

	Elf64_Ehdr ehdr;
	if (read(fd, &ehdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
		perror("read");
		close(fd);
		return 98;
	}

	close(fd);

	printf("ELF Header:\n");
	print_magic(e_ident);
	print_class(e_ident[EI_CLASS]);
	print_data(e_ident[EI_DATA]);
	print_version(e_ident[EI_VERSION]);
	print_osabi(e_ident[EI_OSABI]);
	print_abiversion(e_ident[EI_ABIVERSION]);
	print_type(ehdr.e_type, e_ident[EI_DATA]);
	print_entry(ehdr.e_entry, e_ident[EI_CLASS]);

	return 0;
}
