#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: A pointer to the beginning of the listint_t list.
 *
 * Return: The address of the node where the loop starts,
 *         or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_p = head, *fast_p = head;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;          /* Move slow pointer one step */
		fast_p = fast_p->next->next;    /* Move fast pointer two steps */

		if (slow_p == fast_p)           /* If they meet, then loop exists */
		{
			slow_p = head;              /* Move slow pointer to head */
			while (slow_p != fast_p)    /* They will meet at the start of the loop */
			{
				slow_p = slow_p->next;
				fast_p = fast_p->next;
			}
			return (slow_p);
		}
	}
	return (NULL); /* No loop */
}
#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: A pointer to the beginning of the listint_t list.
 * 
 * Return: The address of the node where the loop starts,
 *         or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow_p = head, *fast_p = head;

    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;          /* Move slow pointer one step */
        fast_p = fast_p->next->next;    /* Move fast pointer two steps */

        if (slow_p == fast_p)           /* If they meet, then loop exists */
        {
            slow_p = head;              /* Move slow pointer to head */
            while (slow_p != fast_p)    /* They will meet at the start of the loop */
            {
                slow_p = slow_p->next;
                fast_p = fast_p->next;
            }
            return (slow_p);
        }
    }
    return (NULL); /* No loop */
}
