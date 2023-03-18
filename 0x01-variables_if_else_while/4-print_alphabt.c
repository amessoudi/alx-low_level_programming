#include <stdio.h>
/**
  * main - print alphabet
  * Prints from a to z then from A to Z
  *
  * Return: Always 0
  */
int main(void)

{
	char c;

	for (c = 'a'; c <= 'z' && c !='q' && c!='e'; ++c)
		putchar(c);
	putchar('\n');
	return (0);
}
