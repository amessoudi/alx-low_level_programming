#include "lists.h"
#include <stdlib.h>

/**
 * print_listint_safe - Print a listint_t linked list.
 * @head: Pointer to the head node of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count = 0;
	const listint_t *slow = head, *fast = head;

	if (!head)
		exit(98);

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			exit(98);
		}
	}


	slow = head;
	while (slow)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		node_count++;
	}

	return (node_count);
}
