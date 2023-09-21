#include "monty.h"

/**
 * push_stack - Function to add nodes to the stack
 * @stack: S-structure
 * @line_number: Number of instructions
 */

void push_stack(stack_t **stack, unsigned int line_number)
{
	main_stack_q(stack, line_number, 0);
}

/**
 * my_stack - function that add node the stack
 * @stack: S-structure
 * @line_number: Number of instructions
 */

void my_stack(stack_t **stack, unsigned int line_number)
{
	main_stack_q(stack, line_number, 1);
}

/**
 * my_q - function that add node the stack
 * @stack: S-structure
 * @line_number: Number of instructions
 */

void my_q(stack_t **stack, unsigned int line_number)
{
	main_stack_q(stack, line_number, 1);
}
