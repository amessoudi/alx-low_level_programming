#include <stdio.h>
/**
 * main - prints fibonnaci sequence
 *
 * Return: Always 0.
 */
int main(void)
{
	int n = 50;
	long long fibonacci[50];

	fibonacci[0] = 1;
	fibonacci[1] = 2;

	for (int i = 2; i < n; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	for (int i = 0; i < n; i++)
	{
		long long num = fibonacci[i];
		char buffer[21];
		int len = 0;

		do {
			buffer[len++] = '0' + (num % 10);
			num /= 10;
		} while (num > 0);

		for (int j = len - 1; j >= 0; j--)
		{
			putchar(buffer[j]);
		}


		if (i < n - 1)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}
