#include "monty.h"
/**
 * mul - adds the top two elements in stack
 * @stack: q
 * @line_number: location of instruction
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *temp2 = *stack;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack)->next;
		temp->n *= temp2->n;
		pop(stack, line_number);
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
