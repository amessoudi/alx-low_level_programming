#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	(void)argv; /* This is to suppress unused variable warning */
	printf("%d\n", argc - 1);
	return (0);
}
