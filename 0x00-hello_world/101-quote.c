#include <unistd.h>
/**
 * main - Entry point
 *
 * Description: writes a message to the stderr pipe
 * Return: Always 1 (Error)
 */
int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);
}