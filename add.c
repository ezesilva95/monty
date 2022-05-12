#include "monty.h"
/**
 * _add - adds the top two elements in stack
 * @stack: top node
 * @line_number: node number
 */
void _add(stack_t **stack, unsigned int line_number)
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
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
