#include <stdio.h>
/**
  * main - print alphabet
  * Prints from a to z
  *
  * Return: Always 0
  */
int main(void)

{
	char c;

	for (c = 'a'; c <= 'z'; ++c)
		putchar(c);
	putchar('\n');
	return (0);
}
