#include "monty.h"
/**
 * add - adds the top two elements in stack
 * @stack: q
 * @line_number: location of instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL || (*stack)->next != NULL)
	{
		(*stack)->next->n += (*stack)->n;
		(*stack) = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
