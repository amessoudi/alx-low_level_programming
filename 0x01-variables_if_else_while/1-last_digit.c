#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - entry point
 *
 * Description: checks if last digit is > 5 =0 or <6 & !=0
 * Return: Always 0 (success)
 */
int main(void)
{
	int n;
	int l;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	l = n % 10;
	printf("Last digit of %d is %d ", n, l);
	if (n > 5)
	{
		printf("and is greater than 5\n");
	}
	else if (n == 0)
	{
		printf("and is 0\n");
	}
	else if (n < 6)
	{
		printf("and is less than 6 and not 0\n");
	}
	return (0);
}
