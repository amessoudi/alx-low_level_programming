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

	for (; n <= 57; n++)
	{
		for (m = n + 1; m <= 57; m++)
		{
			putchar(n);
			putchar(m);
			if (!(n == 56 && m == 57))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar ('\n');
	return (0);
}
