#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function.
 * @argc: number of arguments passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success, 1 or 2 on error
 */
int main(int argc, char *argv[])
{
	int bytes, i;
	char *ptr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	ptr = (char *) main;  /* Cast the address of main function to char pointer */

	for (i = 0; i < bytes; i++)
	{
		printf("%02hhx", ptr[i]);
		if (i < bytes - 1)
			printf(" ");
		else
			printf("\n");
	}

	return (0);
}
