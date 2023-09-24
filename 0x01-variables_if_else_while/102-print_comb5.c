#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all combination of single digit numbers
 * Return:  Always 0 (succss)
 */

int main(void)
{
	int a, b, c, d;

	a = b = 48;

	while (a <= 57)
	{
		b = 48;
		while (b <= 57)
		{
			c = a;
			if (b < 57)
			{
				d = b + 1;
			}
			else
			{
				d = 48;
			}
			while (c <= 57)
			{
				while (d <= 57)
				{
					putchar(a);
					putchar(b);
					putchar(32);
					putchar(c);
					putchar(d);
					
					if(!(c == 57 && d == 57 && a == 57 && b == 56))
					{
						putchar(',');
						putchar(32);
					}
					d++;
				}
				c++;
				d = 48;
			}
			b++;
		}
		a++;
		
	}

	putchar ('\n');
	return (0);
}
