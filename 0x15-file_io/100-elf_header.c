#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <elf.h>

/**
 * print_magic - Prints the magic numbers of the ELF header
 * @e_ident: The identifier of the ELF
 */
void print_magic(unsigned char *e_ident)
{
  int i;

  printf("  Magic:   ");
  for (i = 0; i < EI_NIDENT; i++)
	{
	  printf("%02x ", e_ident[i]);
	}
  printf("\n");
}

/**
 * print_class - Prints the class of the ELF file
 * @ei_class: The class of the ELF file
 */
void print_class(unsigned char ei_class)
{
  printf("  Class:                             ");
  switch (ei_class)
	{
	case ELFCLASS32:
	  printf("ELF32\n");
	  break;
	case ELFCLASS64:
	  printf("ELF64\n");
	  break;
	default:
	  printf("<unknown: %x>\n", ei_class);
	}
}

/**
 * print_data - Prints the data encoding of the ELF file
 * @ei_data: The data encoding of the ELF file
 */
void print_data(unsigned char ei_data)
{
  printf("  Data:                              ");
  switch (ei_data)
	{
	case ELFDATA2LSB:
	  printf("2's complement, little endian\n");
	  break;
	case ELFDATA2MSB:
	  printf("2's complement, big endian\n");
	  break;
	default:
	  printf("<unknown: %x>\n", ei_data);
	}
}

/**
 * print_version - Prints the ELF version
 * @ei_version: The ELF version
 */
void print_version(unsigned char ei_version)
{
  printf("  Version:                           ");
  if (ei_version == EV_CURRENT)
	{
	  printf("1 (current)\n");
	}
  else
	{
	  printf("<unknown: %x>\n", ei_version);
	}
}

/**
 * print_osabi - Prints the Operating System/ABI of the ELF file
 * @ei_osabi: The OS/ABI of the ELF file
 */
void print_osabi(unsigned char ei_osabi)
{
	printf("  OS/ABI:                            ");
	switch (ei_osabi)
	{
	case ELFOSABI_NONE:       printf("UNIX - System V\n");        break;
	case ELFOSABI_HPUX:       printf("UNIX - HP-UX\n");          break;
	case ELFOSABI_NETBSD:     printf("UNIX - NetBSD\n");         break;
	case ELFOSABI_LINUX:      printf("UNIX - Linux\n");          break;
	case ELFOSABI_SOLARIS:    printf("UNIX - Solaris\n");        break;
	case ELFOSABI_AIX:        printf("UNIX - AIX\n");            break;
	case ELFOSABI_IRIX:       printf("UNIX - IRIX\n");           break;
	case ELFOSABI_FREEBSD:    printf("UNIX - FreeBSD\n");        break;
	case ELFOSABI_TRU64:      printf("UNIX - TRU64\n");          break;
	case ELFOSABI_MODESTO:    printf("Novell - Modesto\n");      break;
	case ELFOSABI_OPENBSD:    printf("UNIX - OpenBSD\n");        break;
	case ELFOSABI_ARM_AEABI:  printf("ARM EABI\n");              break;
	case ELFOSABI_ARM:        printf("ARM\n");                   break;
	case ELFOSABI_STANDALONE: printf("Standalone App\n");        break;
	default:                  printf("<unknown: %x>\n", ei_osabi);
	}
}

void print_type(uint16_t e_type, unsigned char ei_data)
{
	/* To avoid unused parameter warning */
	(void) ei_data;

	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_NONE:   printf("NONE (None)\n");                   break;
	case ET_REL:    printf("REL (Relocatable file)\n");        break;
	case ET_EXEC:   printf("EXEC (Executable file)\n");        break;
	case ET_DYN:    printf("DYN (Shared object file)\n");      break;
	case ET_CORE:   printf("CORE (Core file)\n");              break;
	case ET_LOPROC: printf("LOPROC (Processor-specific)\n");   break;
	case ET_HIPROC: printf("HIPROC (Processor-specific)\n");   break;
	default:        printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_abiversion - Prints the ABI version
 * @ei_abiversion: The ABI version
 */
void print_abiversion(unsigned char ei_abiversion)
{
  printf("  ABI Version:                       %u\n", ei_abiversion);
}

/**
 * print_entry - Prints the entry point address of the ELF file
 * @e_entry: The entry point address
 * @ei_class: The class of the ELF file
 */
void print_entry(uint64_t e_entry, unsigned char ei_class)
{
  printf("  Entry point address:               ");
  if (ei_class == ELFCLASS32)
	{
	  printf("0x%x\n", (uint32_t)e_entry);
	}
  else
	{
	  printf("0x%lX\n", e_entry); /* Use %lX instead of %lx for C89 */
	}
}

/**
 * main - The main function
 * @argc: The argument count
 * @argv: The argument vector
 * Return: 0 if successful, 98 if an error occurs
 */
int main(int argc, char **argv)
{
  int fd;
  unsigned char e_ident[EI_NIDENT];
  Elf64_Ehdr ehdr;

  if (argc != 2)
	{
	  fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
	  return 98;
	}

  fd = open(argv[1], O_RDONLY);
  if (fd < 0)
	{
	  perror("open");
	  return 98;
	}

  if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
	{
	  perror("read");
	  close(fd);
	  return 98;
	}

  if (memcmp(e_ident, ELFMAG, SELFMAG) != 0)
	{
	  fprintf(stderr, "Error: Not an ELF file\n");
	  close(fd);
	  return 98;
	}

  if (lseek(fd, 0, SEEK_SET) != 0)
	{
	  perror("lseek");
	  close(fd);
	  return 98;
	}

  if (read(fd, &ehdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
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
