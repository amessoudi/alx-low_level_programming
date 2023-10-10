#include <stdlib.h>

/**
 * main - Entry point of the program.
 *@c: the character to be printed
 * Description: This program prints the name of the file it was
 * compiled from, followed by a new line.
 * Return: 0 if successful, other values for errors.
 */
int _putchar(char c);

int main(void)
{
	char *str = __FILE__;
	char *s = str;

	while (*s)
	{
		_putchar(*s);
		s++;
	}
	_putchar('\n');

	exit(0);
}
