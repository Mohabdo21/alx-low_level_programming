#include "main.h"

/**
 * display_error - Prints an error message and exits the program based on the
 * error code provided.
 * @error_code: The error code.
 * @program_name: The name of the program or file causing the error.
 * @fd: The file descriptor causing the error.
 *
 * Return: Does not return (exit with the provided error code).
 */
void display_error(int error_code, const char *program_name, int fd)
{
	switch (error_code)
	{
		case 97:
			dprintf(2, "Usage: cp file_from file_to\n");
			break;
		case 98:
			dprintf(2, "Error: Can't read from file %s\n", program_name);
			break;
		case 99:
			dprintf(2, "Error: Can't write to %s\n", program_name);
			break;
		case 100:
			dprintf(2, "Error: Can't close fd %d\n", fd);
			break;
	}
	exit(error_code);
}

/**
 * open_file - Opens a file with the specified flags and mode.
 * @filename: The name of the file to open.
 * @flags: The flags to use when opening the file.
 * @mode: The mode to use when opening the file.
 *
 * Return: The file descriptor of the opened file.
 */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
		display_error((flags == O_RDONLY) ? 98 : 99, filename, 0);
	return (fd);
}

/**
 * close_file - Closes a file.
 * @fd: The file descriptor of the file to close.
 *
 */
void close_file(int fd)
{
	if (close(fd) == -1)
		display_error(100, NULL, fd);
}

/**
 * copy_content - Copies content from one file to another.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 * @av: An array of command line arguments.
 *
 */
void copy_content(int fd_from, int fd_to, char **av)
{
	int bytes_read, bytes_written;
	char buffer[1024];

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close_file(fd_from);
			close_file(fd_to);
			display_error(99, av[2], 0);
		}
	}

	if (bytes_read == -1)
	{
		close_file(fd_from);
		close_file(fd_to);
		display_error(98, av[1], 0);
	}
}

/**
 * main - Copies the content of a file to another file.
 * @ac: The number of command line arguments.
 * @av: An array of command line arguments.
 *
 * Return: 0 on success, or an error code as specified in the requirements.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;


	if (ac != 3 || av[1] == NULL || av[2] == NULL)
		display_error(97, av[0], 0);

	fd_from = open_file(av[1], O_RDONLY, 0);

	if (fd_from == -1)
		display_error(98, av[1], 0);

	fd_to = open_file(av[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP |
			S_IWGRP | S_IROTH);

	copy_content(fd_from, fd_to, av);

	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
