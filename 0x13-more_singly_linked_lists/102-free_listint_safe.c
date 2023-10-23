#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: Double pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow_p, *fast_p, *prev;
	size_t nodes = 0;

	if (!h || !*h)
		return (0);

	slow_p = *h;
	fast_p = *h;

	while (slow_p && fast_p && fast_p->next)
	{
		prev = slow_p;
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		nodes++;

		if (slow_p == fast_p)
		{
			/* Break the loop */
			prev->next = NULL;
			break;
		}
	}

	while (*h)
	{
		prev = *h;
		*h = (*h)->next;
		free(prev);
		nodes++;
	}

	*h = NULL; /* Set head to NULL */

	return (nodes);
}
