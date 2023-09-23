#include <stdio.h>

/**
 * main - entry point
 *
 * Description: prints whole alphabet from a to z lowercase
 * Return: Always 0 (success)
 */
int main(void)
{
	int n;

	n = 97;

	while (n < 123)
	{
		putchar(n);
		n++;
	}
	n = 65;

	while (n < 91)
	{
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}
