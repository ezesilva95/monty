#include "monty.h"
/**
 *pint - prints the value at the top of the stack
 *@stack: a
 *@line_number: location of the instruction
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", new_node->n);
}
