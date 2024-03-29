#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Double pointer to the head of the linked list.
 * @idx: Index where the new node should be added, starting at 0.
 * @n: Integer data for the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp;
	unsigned int i;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	temp = *head;
	for (i = 1; i < idx && temp; i++)
	{
		temp = temp->next;
	}

	if (!temp)
	{
		free(new_node);
		return (NULL);
	}


	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}
