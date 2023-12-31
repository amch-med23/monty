#include "monty.h"

/**
 * _nothing - Function that frees if there is not coincidence
 * @stack: stack structure
 * @line_number: Number of instruction
 */
void _nothing(stack_t **stack, UNUSED unsigned int line_number)
{
	if (list_opcode)
		free_opcode(list_opcode);

	if (*stack)
		free_stack(*stack);

	exit(EXIT_FAILURE);
}
