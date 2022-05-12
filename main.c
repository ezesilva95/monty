#include "monty.h"
/**
 * main - entry point of interpreter
 * @argc: argcuments counter
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	unsigned int line_n = 0;
	FILE *file_d;
	char *token, *str;
	size_t size = 0;
	stack_t *stack = NULL;
	
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_d = popen(argv[1], "r");
	if (file_d == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&str, &size, file_d) != -1)
	{
		line_n++;
		token = strtok(str, "\n\t");
		if (token == NULL || token[0] == '#')
			continue;
		if (get_function(token, &stack, line_n) == 1)
		{
			printf("L%d: unknown instruction %s\n", line_n, token);
			free(stack), free(str);
			exit(EXIT_FAILURE);
		}
	}
	free(stack), free(str);
	return (0);
}
