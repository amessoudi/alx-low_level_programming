#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - Print a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow_p = head, *fast_p = head;
	size_t nodes = 0;

	if (!head)
		exit(98);

	while (slow_p && fast_p && fast_p->next)
	{
		printf("[%p] %d\n", (void *)slow_p, slow_p->n);
		nodes++;

		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		if (slow_p == fast_p)
		{
			printf("-> [%p] %d\n", (void *)slow_p, slow_p->n);
			return (nodes + 1);
		}
	}

	while (slow_p)
	{
		printf("[%p] %d\n", (void *)slow_p, slow_p->n);
		nodes++;
		slow_p = slow_p->next;
	}

	return (nodes);
}
