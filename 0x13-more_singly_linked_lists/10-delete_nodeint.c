#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a specific index
 * @head: Double pointer to the head of the linked list.
 * @index: The index of the node that should be deleted, starting at 0.
 *
 * Return: 1 if succeeded, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}


	for (i = 1; i < index && current != NULL; i++)
	{
		current = current->next;
	}


	if (current == NULL || current->next == NULL)
		return (-1);


	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}
