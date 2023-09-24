#include <stdio.h>

/**
 * main - entry level
 *
 * Description; prints base16 in lowercase
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n;

	for (n = 48; n <= 102; n++)
	{
		if ((n  <=  57) ||  (n  >=  97))
			putchar(n);
	}
	putchar('\n');
	return (0);
}
