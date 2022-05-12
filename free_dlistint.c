#include "monty.h"
/**
 *free_dlistint - frees a list_t list.
 *@head: point to the list
 **/

void free_dlistint(stack_t *head)
{
	stack_t *i;

	while (head != NULL)
	{
		i = head;
		head = head->next;
		free(i);
	}
	free(head);
}
