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
	size_t node_count = 0;
	const listint_t *hare, *tortoise;

	if (!head)
		return (0);

	tortoise = head;
	hare = head;

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		/* If there's a loop, hare and tortoise pointers will meet at some point */
		if (tortoise == hare)
		{
			while (head != hare)
			{
				printf("[%p] %d\n", (void *)head, head->n);
				head = head->next;
				node_count++;
			}
			printf("-> [%p] %d\n", (void *)hare, hare->n);
			return (node_count + 1);
		}
	}

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		node_count++;
	}

	return (node_count);
}
