#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	(void)argc; /* This is to suppress unused variable warning */
	printf("%s\n", argv[0]);
	return (0);
}
