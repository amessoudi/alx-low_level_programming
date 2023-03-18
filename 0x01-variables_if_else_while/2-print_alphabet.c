#include <stdio.h>

/* this fuction displays the alphabet in lowercase */

int main(void)

{
	char c;

	for (c = 'a'; c <= 'z'; ++c)
		putchar(c);
	putchar('\n');
	return (0);
}
