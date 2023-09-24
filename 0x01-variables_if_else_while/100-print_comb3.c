#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all combination of single digit numbers
 * Return:  Always 0 (succss)
 */

int main(void)
{
	int n;
	int m;

	n = 48;
	m = 49;

	for (; n <= 57; n++)
	{
		for (; (m <= 57) && (m != n); n++)
		{
			putchar(n);
			putchar(m);
			putchar(',');
			putchar(' ');
		}
	}
	putchar ('\n');
	return (0);
}
