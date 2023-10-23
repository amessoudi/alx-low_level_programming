#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list.
 * @head: A double pointer to the beginning of the listint_t list.
 * @n: The integer to be included in the new node.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new element.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
