#include "main.h"

/**
 * push - pushes an element of the stack.
 * @stack: a
 * @line_number: location of the instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *nmb;
	int num = 0;

	node = malloc(sizeof(stack_t));
	nmb = strtok(NULL, " \n\t");
	if (node == NULL)
	{
		printf(stderr, "Error: malloc failed\n");
		if (*stack != NULL)
		{
			free(stack);
		}
		exit(EXIT_FAILURE);
	}
	num = aoti(nmb);
	if (nmb == NULL || is_number(nmb) == -1)
	{
		printf(stderr, "L%d: usage: push integer\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	node->n = num;
	node->prev = NULL;
	if (*stack == NULL)
	{
		node->next = NULL;
		*stack = node;
	}
	else
	{
		node->next = *stack;
		(*stack)->prev = node;
		*stack = node;
	}
}

/**
 * pall -  prints all the values on the stack
 * @stack: a
 * @line_number: location of the instruction*
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	if (!stack || !*stack)
		return;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
