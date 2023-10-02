#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * main - Entry point of the ELF Header display program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return:
 * - 0 on successful execution.
 * - 98 if there is an issue with the number of arguments or opening the file.
 *   A corresponding error message is displayed on standard error.
 * - 98 if the ELF file format is invalid or not supported.
 *   A corresponding error message is displayed on standard error.
 */
int main(int argc, char **argv)
{
	int fd;
	ssize_t bytes;
	int i;
	Elf64_Ehdr ehdr;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(98);
	}

	bytes = read(fd, &ehdr, sizeof(ehdr));
	if (bytes != sizeof(ehdr))
	{
		perror("Error reading ELF header");
		exit(98);
	}

	if (ehdr.e_ident[EI_MAG0] != ELFMAG0 ||
			ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
			ehdr.e_ident[EI_MAG2] != ELFMAG2 ||
			ehdr.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Not an ELF file\n");
		exit(98);
	}

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ehdr.e_ident[i]);
	printf("\n");

	printf("Class:                             %s\n", ehdr.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("Data:                              %s\n", ehdr.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("Version:                           %d (current)\n", ehdr.e_ident[EI_VERSION]);
	printf("OS/ABI:                            UNIX - System V\n");
	printf("ABI Version:                       %d\n", ehdr.e_ident[EI_OSABI]);
	printf("Type:                              %s\n", ehdr.e_type == ET_EXEC ? "EXEC (Executable file)" : "Unknown");
	printf("Entry point address:               0x%lx\n", ehdr.e_entry);

	close(fd);

	return (0);
}

