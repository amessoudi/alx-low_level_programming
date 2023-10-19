#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
void print_list(const list_t *head);


#endif /* LISTS_H */
