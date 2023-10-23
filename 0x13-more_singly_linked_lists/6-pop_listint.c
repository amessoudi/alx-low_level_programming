#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - Pops a listint_t list.
 * @head: Pointer to the head of the list.
 *
 *Return: n
 */

int pop_listint(listint_t **head)
{
	int n;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	temp = *head;
	n = temp->n;
	*head = (*head)->next;
	free(temp);

	return (n);
}

