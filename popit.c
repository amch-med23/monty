#include "monty.h"

/**
 * pop_stack - Function that remove 1st stack
 * @stack: S-structure
 * @line_number: Number of instructions
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo = NULL;
	int n;

	n = stack_len(*stack);
	if (n <= 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		if (list_opcode != NULL)
			free_list_opcode(list_opcode);
		if (*stack != NULL)
			free_list_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}

	tempo = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tempo);
	tempo = NULL;
}
