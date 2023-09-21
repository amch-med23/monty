#include "monty.h"

/**
 * pintit - function that print the value at
 * the beg of the stack
 * @stack: S-structure
 * @line_number: Number of instructions
 */

void pintit(stack_t **stack, unsigned int line_number)
{


	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_list_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
