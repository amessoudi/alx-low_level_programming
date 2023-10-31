#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <elf.h>

void print_class(unsigned char class) {
	printf("  Class:                             ");
	switch (class) {
		case ELFCLASS32: printf("ELF32\n"); break;
		case ELFCLASS64: printf("ELF64\n"); break;
		default: printf("<unknown: %x>\n", class);
	}
}

void print_data(unsigned char data) {
	printf("  Data:                              ");
	switch (data) {
		case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
		case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
		default: printf("<unknown: %x>\n", data);
	}
}

void print_version(unsigned char version) {
	printf("  Version:                           %d ", version);
	if (version == EV_CURRENT) {
		printf("(current)\n");
	} else {
		printf("\n");
	}
}

void print_osabi(unsigned char osabi) {
	printf("  OS/ABI:                            ");
	switch (osabi) {
		case ELFOSABI_SYSV:       printf("UNIX - System V\n"); break;
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
		case ELFOSABI_ARM_AEABI:  printf("ARM EABI\n"); break;
		case ELFOSABI_ARM:        printf("ARM\n"); break;
		case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
		default: printf("<unknown: %x>\n", osabi);
	}
}

void print_type(unsigned short type) {
	printf("  Type:                              ");
	switch (type) {
		case ET_NONE:   printf("NONE (No file type)\n"); break;
		case ET_REL:    printf("REL (Relocatable file)\n"); break;
		case ET_EXEC:   printf("EXEC (Executable file)\n"); break;
		case ET_DYN:    printf("DYN (Shared object file)\n"); break;
		case ET_CORE:   printf("CORE (Core file)\n"); break;
		default:        printf("<unknown: %x>\n", type);
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		exit(98);
	}

	unsigned char e_ident[EI_NIDENT];
	if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT) {
		fprintf(stderr, "Error reading ELF identification\n");
		close(fd);
		exit(98);
	}

	if (memcmp(e_ident, ELFMAG, SELFMAG) != 0) {
		fprintf(stderr, "Not an ELF file\n");
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++) {
		printf("%02x ", e_ident[i]);
	}
	printf("\n");

	print_class(e_ident[EI_CLASS]);
	print_data(e_ident[EI_DATA]);
	print_version(e_ident[EI_VERSION]);
	print_osabi(e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);

	if (e_ident[EI_CLASS] == ELFCLASS32) {
		Elf32_Ehdr header;
		if (pread(fd, &header, sizeof(header), 0) != sizeof(header)) {
			fprintf(stderr, "Error reading ELF header\n");
			close(fd);
			exit(98);
		}
		print_type(header.e_type);
		printf("  Entry point address:               0x%x\n", header.e_entry);
	} else if (e_ident[EI_CLASS] == ELFCLASS64) {
		Elf64_Ehdr header;
		if (pread(fd, &header, sizeof(header), 0) != sizeof(header)) {
			fprintf(stderr, "Error reading ELF header\n");
			close(fd);
			exit(98);
		}
		print_type(header.e_type);
		printf("  Entry point address:               0x%lx\n", header.e_entry);
	} else {
		fprintf(stderr, "Unsupported ELF class %d\n", e_ident[EI_CLASS]);
		close(fd);
		exit(98);
	}

	close(fd);
	return 0;
}
