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

	};
	int i = 0;

	while (instruct[i].f != NULL)
	{
		if (strcmp(tok, instruct[i].opcode) == 0)
			return (instruct.f);
		i++;
	}
	return (NULL);
}
