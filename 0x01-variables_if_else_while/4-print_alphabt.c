#include <stdio.h>

/**
 * main - entry point
 *
 *Description: prints lowercase alphabet escept "e" and "q"
 *Return: Always 0 (success)
 */

int main(void)
{
	char n;

	for ( n = 'a'; n <= 'z'; n++)
	{	
	       	if ( n != 'e' && n != 'q')
			putchar(n);
	}
	putchar('\n');
	return (0);
}
