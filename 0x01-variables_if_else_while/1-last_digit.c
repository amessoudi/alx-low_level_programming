#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/* betty style doc for function main goes there */
/**
 * main - Prints a random number and states whether
 *        it is greater than 5, lesst than 6 and not Zero, or zero.
 *
 * Return: Always 0.
*/
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 5)
		printf("Last digit of %d is %d and is greater than 5\n", n, n % 10);
	else if (n == 0)
		printf("Last digit of %d is %d and is 0\n", n, n % 10);
	else if (n < 6 && n != 0)
		printf("Last digit of %d is %d and is less than 6 but not 0\n", n, n % 10);
	return (0);
}
