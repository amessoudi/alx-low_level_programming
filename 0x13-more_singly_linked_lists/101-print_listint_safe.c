#include "lists.h"
#include <stdio.h>
/**
 * print_listint_safe - Print a listint_t linked list safely.
 * @head: Pointer to the head node of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t nodes = 0;

	if (!head)
		return (0);

	tortoise = head;
	hare = head;

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				printf("[%p] %d\n", (void *)tortoise, tortoise->n);
				tortoise = tortoise->next;
				nodes++;
			}
			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
			nodes++;
			while (hare->next != tortoise)
			{
				hare = hare->next;
				printf("[%p] %d\n", (void *)hare, hare->n);
				nodes++;
			}
			printf("-> [%p] %d\n", (void *)hare, hare->n);
			return (nodes);
		}
	}
	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		nodes++;
		head = head->next;
	}
	return (nodes);
}
