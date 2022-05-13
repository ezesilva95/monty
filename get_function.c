#include "monty.h"

/**
 * get_function - get the correct function
 * @tok: inst.
 * @stack: a
 * @line_number: location of innstruction
 * Return: pointer to correct function
 */
int get_function(char *tok, stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL},

	};
	int i = 0, s = 1;

	while (instruct[i].opcode != NULL)
	{
		if (strcmp(tok, instruct[i].opcode) == 0)
		{
			instruct[i].f(stack, line_number);
			s = 0;
		}
		i++;
	}
	return (s);
}
