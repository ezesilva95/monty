#include "monty.h"
/**
 * pop - removes the top element of the stack.
 * @stack: a
 * @line_number: location of the instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_dlistint(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
