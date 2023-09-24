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

	for (n = 48; n <= 57; n++)
	{
		putchar(n);
		if (n <= 56)
		{
			putchar(',');
			putchar(32);
		}
	}
	putchar ('\n');
	return (0);
}
