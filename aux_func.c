#include "monty.h"

/**
 * is_number - check if char are numers
 * @nmb: n
 * Return: 0 if success -1 if not
 */
int is_number(char *nmb)
{
	int i = 0;

	if (nmb[0] == '-')
		i = 1;
	while (nmb[i] != '\0')
	{
		if (nmb[i] < '0' || nmb[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}
