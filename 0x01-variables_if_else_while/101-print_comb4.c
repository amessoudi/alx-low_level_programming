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
	int i;

	n = 48;

	for (; n <= 57; n++)
	{
		for (m = n + 1; m <= 57; m++)
		{
			for (i = m + 1; i <= 57; i++)
			{
				putchar(n);
				putchar(m);
				putchar(i);
				if (!(n == 55 && m == 56 && i == 57))
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar ('\n');
	return (0);
}
