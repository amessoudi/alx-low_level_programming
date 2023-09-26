#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet in lowercase 10 times,
 * each followed by a new line.
 */
void print_alphabet_x10(void)
{
	int i;
	char c;

	for (i = 0; i < 10; i++) /* Outer loop to run the alphabet 10 times */
	{
		for (c = 'a'; c <= 'z'; c++) /* Inner loop to print the alphabet */
			_putchar(c); /* This is the first use of _putchar */

		_putchar('\n'); /* This is the second use of _putchar */
	}
}
