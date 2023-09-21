#include "monty.h"

/**
 * swap_stack - Function that swaps two stack values
 * @stack: S- structure
 * @line_number: Number of instructions
 */
void swap_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo = NULL;
	int n;

	n = stack_len(*stack);
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		if (list_opcode != NULL)
			free_list_opcode(list_opcode);
		if (*stack != NULL)
			free_list_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if (n == 2)
	{
		tempo = (*stack)->next;
		(*stack)->next = NULL;
		(*stack)->prev = tempo;
		tempo->prev = NULL;
		tempo->next = *stack;
		*stack = tempo;
	}
	else
	{
		tempo = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		(*stack)->prev = tempo;
		tempo->next->prev = *stack;
		tempo->prev = NULL;
		tempo->next = *stack;
		*stack = tempo;
	}
}
