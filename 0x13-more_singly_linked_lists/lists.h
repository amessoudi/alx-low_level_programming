#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>  /* For size_t */

/**
 * struct listint_s - singly linked list for integers
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure for integers
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
size_t listint_len(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
listint_t *add_nodeint_end(listint_t **head, const int n);
listint_t *find_listint_loop(listint_t *head);

#endif /* LISTS_H */
