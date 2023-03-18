#include <stdio.h>

/* This code prints the alphabet */
/* The alphabet trick*/
int main(void) /* Is this how you  describe it betty+? */
{
	char c;

	for (c = 'a'; c <= 'z'; ++c)
		putchar(c);
	putchar('\n');
	return (0);
}
