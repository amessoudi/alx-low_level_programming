#include <stdio.h>

/* this fuction displays the alphabet in lowercase */

int main(void) /* is this what you want? */

{
	char c;

	for (c = 'a'; c <= 'z'; ++c)
		putchar(c);
	putchar('\n');
	return (0);
}
