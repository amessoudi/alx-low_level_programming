#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all combination of single digit numbers
 * return :  Always 0 (succss)
 */

int main(void)
{
	int n;

	for (n = 48; n <= 57; n++)
	{
		putchar(n);
		putchar(',');
		putchar(32);
	}
	putchar ('\n');
	return 0;
}
