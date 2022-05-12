#include "monty.h"

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

	nmb = strtok(NULL, " \n\t");
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (*stack != NULL)
		{
			free_dlistint(*stack);
		}
		exit(EXIT_FAILURE);
	}
	if (nmb == NULL || is_number(nmb) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	num = atoi(nmb);
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
	(void) line_number;
	if (!*stack)
		return;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
