#include "main.h"
/**
 * set_string - sets the value of a pointer to a char
 * @s: ptr to ptr
 * @to: ptr to char
 * Return: void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
