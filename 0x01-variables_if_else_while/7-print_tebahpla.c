#include <stdio.h>

/**
 * main - entry point
 *
 * Description: prints whole alphabet from z to a lowercase
 * Return: Always 0 (success)
 */
int main(void)
{
	int n;

	n = 122;

	while (n >= 97)
	{
		putchar(n);
		n--;
	}
	putchar('\n');
	return (0);
}
