#include "monty.h"
/**
 * pop - removes the top element of the stack.
 * @stack: a
 * @line_number: location of the instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*stack)->next == NULL)
		{
			*stack = NULL;
			free(temp);
		}
		else
		{
			*stack = (*stack)->next;
			(*stack)->prev = NULL;
			free(temp);
		}
	}
}
