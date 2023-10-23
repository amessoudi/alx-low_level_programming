#include "lists.h"
#include <stdlib.h>

/**
 * sum_listint - returns the sum of all the data of linked list.
 * @head: pointer to the head of the linked list.
 *
 * Return: sum of all the data in the list. If the list is empty, returns 0.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
