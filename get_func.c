#include "monty.h"

/**
 * get_func - get the correct function
 * @token1: inst.
 * Return: pointer to correct function
 */
int get_function(char *tok, stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", pop},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"nop", nop},

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
