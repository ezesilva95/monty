#include "monty.h"
/*
* div - div secnd top element by the top
* @stack: a
* line_number: lcoation of instruction
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp2 = *stack, *temp;

	if (*stack != NULL && (*stack)->next == NULL)
	{
		temp = (*stack)->next;
		temp->n /= temp2->n;
		pop(stack, line_number);
		*stack = temp;
	}
	if (temp2->n)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
	}
	else
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
