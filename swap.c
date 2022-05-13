#include "monty.h"

/**
 * swap - swap the top two elements of the stack.
 * @stack: a
 * @line_number: number of line wich contain the instruction..
 **/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *temp2;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp2 = temp->next;
		temp->prev = *stack;
		temp->next = temp2->next;
		temp2->prev = NULL;
		temp2->next = temp;
		(*stack) = temp2;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
