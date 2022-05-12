#include "monty.h"
/**
 * main - entry point of interpreter
 * @argc: argcuments counter
 * @argv: argument
 * Return: 0
 */
int main(int argc, char *argv[])
{
	unsigned int line_n = 0;
	FILE *file_d;
	char *token, *str = NULL;
	size_t size = 0;
	stack_t *stack = NULL;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_d = fopen(argv[1], "r");
	if (file_d == NULL)
	{
		fprintf(stderr,"Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (getline(&str, &size, file_d) == -1)
			break;
		line_n++;
		token = strtok(str, " \t\n");
		if (get_function(token, &stack, line_n) == 1)
		{
			fprintf(stderr, "L%i: unkown instruction %s\n", line_n, token);
			free_dlistint(stack);
			free(str);
			fclose(file_d);
			exit(EXIT_FAILURE);
		}
	}
	free_dlistint(stack);
	free(str);
	fclose(file_d);
	return (0);
}
