#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_elf_header - Prints ELF header info.
 * @header: Pointer to an Elf64_Ehdr structure.
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n", header->e_ident[EI_CLASS]
			== ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n", header->e_ident[EI_DATA]
			== ELFDATA2LSB ? "2's complement, little endian"
			: "2's complement, big endian");
	printf("  Version:                           %d (current)\n",
			header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", header->e_ident[EI_OSABI]
			== ELFOSABI_SYSV ? "UNIX - System V" : "<unknown>");
	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", header->e_type
			== ET_EXEC ? "EXEC (Executable file)" : "DYN (Shared object file)");
	printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/**
 * main - Program entry point.
 * @argc: Number of command-line arguments.
 * @argv: Array of pointers to the command-line arguments.
 *
 * Return: 0 on success, or 98 on error or if file is not an ELF file.
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		perror("Error reading ELF header");
		return (98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Not an ELF file\n");
		return (98);
	}

	print_elf_header(&header);

	close(fd);
	return (0);
}
