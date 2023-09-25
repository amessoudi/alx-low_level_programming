#include "main.h"
/**
 * _memcpy - Entry point
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy from src to dst
 *
 * Description: copies n bytes from src to dst
 * Return: *dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n, i++)
	{
		dest[i] = src[i];
	}
	return dest;
}
