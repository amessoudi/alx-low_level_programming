#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all combination of single digit numbers
 * Return:  Always 0 (succss)
 */

int main(void)
{
	int a;
	int b;
	int c;
	int d;

	a = b = c = 48;
	d = 49;

	while (a <= 57)
	{
		c = 48;
		while (c <= 57)
		{
			d = 49;
			while (d <= 57)
			{
				putchar(a);
				putchar(b);
				putchar(32);
				putchar(c);
				putchar(d);
				if(!(a == 57 && b == 56 && c == 57 && d == 57))
				{
					putchar(',');
					putchar(32);
					d++;
				}
			}
			c++;
		}
		b++;
		if (b > 57)
		{
			b = 48;
		}
		a++;
	}		

	putchar ('\n');
	return (0);
}
