#include "monty.h"

/**
 * add_stack - function that add nodes on top
 * @stack: S-structure
 * @line_number: Number of instructions
 */

void add_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo = NULL;
	int n;

	n = stack_len(*stack);
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		if (list_opcode != NULL)
			free_list_opcode(list_opcode);
		if (*stack != NULL)
			free_list_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tempo = *stack;
	tempo->next->n += tempo->n;
	pop_stack(stack, line_manager);
}
